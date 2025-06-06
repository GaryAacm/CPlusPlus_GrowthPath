1、被 volatile 修饰的变量，在对其进行读写操作时，会引发一些**可观测的副作用**。而这些可观测的副作用，是由**程序之外的因素决定的**。

在C++中，volatile 是一个类型修饰符，用于告诉编译器不要对标记为 volatile 的变量进行优化，因为这些变量的值可能会在程序的控制之外被意外修改。

2.volatile应用
（1）并行设备的硬件寄存器（如状态寄存器）。 假设要对一个设备进行初始化，此设备的某一个寄存器为0xff800000。


int  *output = (unsigned  int *)0xff800000; //定义一个IO端口；  
int   init(void)  
{  
    int i;  
    for(i=0;i< 10;i++)
    {  
    *output = i;  
    }  
}
经过编译器优化后，编译器认为前面循环半天都是废话，对最后的结果毫无影响，因为最终只是将output这个指针赋值为 9，所以编译器最后给你编译编译的代码结果相当于：

int  init(void)  
{  
    *output = 9;  
}
如果你对此外部设备进行初始化的过程是必须是像上面代码一样顺序的对其赋值，显然优化过程并不能达到目的。反之如果你不是对此端口反复写操作，而是反复读操作，其结果是一样的，编译器在优化后，也许你的代码对此地址的读操作只做了一次。然而从代码角度看是没有任何问题的。这时候就该使用volatile通知编译器这个变量是一个不稳定的，在遇到此变量时候不要优化。

3、多线程应用中被多个任务共享的变量。 当多个线程共享某一个变量时，该变量的值会被某一个线程更改，应该用 volatile 声明。作用是防止编译器优化把变量从内存装入CPU寄存器中，当一个线程更改变量后，未及时同步到其它线程中导致程序出错。volatile的意思是让编译器每次操作该变量时一定要从内存中真正取出，而不是使用已经存在寄存器中的值。

示例如下：


volatile  bool bStop=false;  //bStop 为共享全局变量  
//第一个线程
void threadFunc1()
{
    ...
    while(!bStop){...}
}
//第二个线程终止上面的线程循环
void threadFunc2()
{
    ...
    bStop = true;
}


5、volatile常见问题
下面的问题可以看一下面试者是不是直正了解volatile。 
（1）一个参数既可以是const还可以是volatile吗？为什么？ 
可以。一个例子是只读的状态寄存器。它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。

（2）一个指针可以是volatile吗？为什么？ 
可以。尽管这并不常见。一个例子是当一个中断服务子程序修该一个指向一个buffer的指针时。

6、
volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素（操作系统、硬件、其它线程等）更改。所以使用 volatile 告诉编译器不应对这样的对象进行优化。

7、
volatile 关键字声明的变量，每次访问时都必须从内存中取出值（没有被 volatile 修饰的变量，可能由于编译器的优化，从 CPU 寄存器中取值）

const 可以是 volatile （如只读的状态寄存器）
指针可以是 volatile

信号处理或多线程（但不够！）
在信号处理函数或某些多线程场景中，volatile 可以防止编译器优化导致的数据不一致。但注意：

volatile 不能替代原子操作或同步机制（如 std::atomic 或互斥锁），因为它不保证操作的原子性，也不解决内存可见性问题（可能因CPU缓存导致问题）。

C++11 后，多线程场景应优先使用 std::atomic

bool expected = false;
if (data->is_reading.compare_exchange_strong(expected, true))
使用了原子操作

compare_exchange_strong 是 std::atomic 提供的原子操作，功能如下：

比较并交换：检查 is_reading 的当前值是否等于 expected（即 false）。

原子性修改：
如果相等，将 is_reading 设置为 true 并返回 true。
如果不相等（说明其他线程/信号已持有锁），直接返回 false。

作用：实现了一个简单的自旋锁，确保同一时间只有一个执行流（线程或信号处理函数）能进入临界区

```cpp
void MaxPlot::posix_timer_handler(union sigval sv)
{
    MAX30102 *data = static_cast<MAX30102 *>(sv.sival_ptr);

    // 尝试将 is_reading 从 false 设置为 true
    bool expected = false;
    if (data->is_reading.compare_exchange_strong(expected, true))
    {

        data->get_data();

        data->datacount++;
        if (data->datacount >= 3600)
        {
            std::cout << "data is up to full" << std::endl;

            cout << "Data count is " << data->datacount << endl;
            data->datacount = 0;
            emit data->finishRead();
            data->Quit();

            cout << "Jump is:" << data->count_Jump << endl;

            data->count_Jump = 0;
        }

        data->is_reading = false;
    }
    else
    {

        std::cerr << "上一次读取未完成，跳过此次读取" << std::endl;
        data->count_Jump++;
        data->datacount++;
    }
}
```
