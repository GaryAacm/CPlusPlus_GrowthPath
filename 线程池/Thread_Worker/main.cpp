#include "IWorker.h"

int main()
{
    ThreadPool pool;

    for (int i = 1; i <= 5; i++)
    {
        pool.addJob(new CalcWorker(i, i));
    }

    cout << "Total threads is:" << pool.getThreadNum() << endl;

    while (!pool.isAllFinish())
    {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Process count is:" << pool.getProcessCount() << endl;
    }

    std::cout << "All tasks finished. Total count: "
              << pool.getProcessCount() << "\n";

    return 0;
}