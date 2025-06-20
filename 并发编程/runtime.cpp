#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

// 累加结构体
template <typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T &result)
    {
        result = accumulate(first, last, result);
    }
};

template <typename Iterator, typename T>
T parallel_accumlate(Iterator first, Iterator last, T init)
{
    unsigned long const length = std::distance(first, last);
    if (!length)
        return init;

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length+min_per_thread-1)/min_per_thread;
    cout<<"max thread is:"<<max_threads<<endl;

    unsigned long const hardware_threads = thread::hardware_concurrency();
    cout<<"hardware thread is:"<<hardware_threads<<endl;

    unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    cout<<"num_thread is:"<<num_threads<<endl;

    unsigned long const block_size = length/num_threads;
    cout<<"block size is:"<<block_size<<endl;

    vector<T> results(num_threads);
    vector<thread> threads(num_threads - 1);

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        advance(block_end, block_size);
        threads[i] = thread(accumulate_block<Iterator, T>(), block_start, block_end, ref(results[i]));
        block_start = block_end;
    }
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    for_each(threads.begin(), threads.end(), mem_fn(&thread::join));

    return accumulate(results.begin(), results.end(), init);
}

int main()
{
    vector<int> v{3,4,5,6};
    int res =0;
    cout<<parallel_accumlate(v.begin(),v.end(),res)<<endl;
    return 0;
}
