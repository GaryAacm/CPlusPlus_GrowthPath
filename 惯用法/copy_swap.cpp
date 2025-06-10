#include <iostream>
using namespace std;

namespace A
{
    template <typename T>
    class smart_ptr
    {
    public:
        smart_ptr() noexcept : ptr_(new T())
        {
        }

        smart_ptr(const T &ptr) noexcept : ptr_(new T(ptr))
        {
        }

        smart_ptr(smart_ptr &rhs) noexcept
        {
            ptr_ = rhs.release(); // 释放所有权,此时rhs的ptr_指针为nullptr
        }

        void swap(smart_ptr &rhs) noexcept
        { // noexcept == throw() 保证不抛出异常
            using std::swap;
            swap(ptr_, rhs.ptr_);
        }

        T *release() noexcept
        {
            T *ptr = ptr_;
            ptr_ = nullptr;
            return ptr;
        }

        T *get() const noexcept
        {
            return ptr_;
        }

    private:
        T *ptr_;
    };

    // 提供一个非成员swap函数for ADL(Argument Dependent Lookup)
    template <typename T>
    void swap(A::smart_ptr<T> &lhs, A::smart_ptr<T> &rhs) noexcept
    {
        lhs.swap(rhs);
    }
}
// 注释开启,会引发ADL冲突
// namespace std {
//    // 提供一个非成员swap函数for ADL(Argument Dependent Lookup)
//    template<typename T>
//    void swap(A::smart_ptr<T> &lhs, A::smart_ptr<T> &rhs) noexcept {
//        lhs.swap(rhs);
//    }
//
//}

int main()
{

    using std::swap;
    A::smart_ptr<std::string> s1("hello"), s2("world");
    // 交换前
    std::cout << *s1.get() << " " << *s2.get() << std::endl;
    swap(s1, s2); // 这里swap 能够通过Koenig搜索或者说ADL根据s1与s2的命名空间来查找swap函数
    // 交换后
    std::cout << *s1.get() << " " << *s2.get() << std::endl;
    s1 = s2;
}