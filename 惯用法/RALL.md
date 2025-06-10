在C语言中，有三种类型的内存分配:静态、自动和动态。静态变量是嵌入在源文件中的常数，因为它们有已知的大小并且从不改变，所以它们并不那么有趣。自动分配可以被认为是堆栈分配——当一个词法块进入时分配空间，当该块退出时释放空间。它最重要的特征与此直接相关。在C99之前，自动分配的变量需要在编译时知道它们的大小。这意味着任何字符串、列表、映射以及从这些派生的任何结构都必须存在于堆中的动态内存中。

程序员使用四个基本操作明确地分配和释放动态内存:malloc、realloc、calloc和free。前两个不执行任何初始化，内存可能包含碎片。除了自由，他们都可能失败。在这种情况下，它们返回一个空指针，其访问是未定义的行为；在最好的情况下，你的程序会崩溃。在最坏的情况下，你的程序看起来会工作一段时间，在崩溃前处理垃圾数据。

至少可以说，所有手动管理都是令人不快的。 在80年代中期，Bjarne Stroustrup为他的全新语言C ++发明了一种新的范例。 他将其称为“资源获取就是初始化”，其基本见解如下：可以指定对象具有构造函数和析构函数，这些构造函数和析构函数在适当的时候由编译器自动调用，这为管理给定对象的内存提供了更为方便的方法。 需要，并且该技术对于不是内存的资源也很有用。


2.“使用垃圾收集器，flyboy！”¶
垃圾收集器不是一项新技术。 它们由John McCarthy在1959年为Lisp发明。 1980年，随着Smalltalk-80的出现，垃圾收集开始成为主流。 但是，1990年代代表了该技术的真正发芽：在1990年至2000年之间，发布了多种语言，所有语言都使用一种或另一种垃圾回收：Haskell，Python，Lua，Java，JavaScript，Ruby，OCaml 和C＃是最著名的。

什么是垃圾收集？ 简而言之，这是一组用于自动执行手动内存管理的技术。 它通常作为具有手动内存管理的语言（例如C和C ++）的库提供，但在需要它的语言中更常用。 最大的优点是程序员根本不需要考虑内存。 都被抽象了。 例如，相当于我们上面的文件读取代码的Python就是这样：


def read_lines_from_file(file_name):
    lines = []
    with open(file_name) as fp: 
        for line in fp:
            lines.append(line)
    return lines

if __name__ == '__main__':
    import sys
    file_name = sys.argv[1]
    count = len(read_lines_from_file(file_name))
    print("File {} contains {} lines.".format(file_name, count))
行数组是在第一次分配给它时出现的，并且不复制到调用范围就返回。 由于时间不确定，它会在超出该范围后的某个时间被垃圾收集器清理。 有趣的是，在Python中，用于非内存资源的RAII不是惯用语言。 允许-我们可以简单地编写fp = open（file_name）而不是使用with块，然后让GC清理。 但是建议的模式是在可能的情况下使用上下文管理器，以便可以在确定的时间释放它们。

尽管简化了内存管理，但要付出很大的代价。 在引用计数垃圾回收中，所有变量赋值和作用域出口都会获得少量成本来更新引用。 在标记清除系统中，在GC清除内存的同时，所有程序的执行都以不可预测的时间间隔暂停。 这通常称为世界停止事件。 同时使用这两种系统的Python之类的实现都会受到两种惩罚。 这些问题降低了垃圾收集语言在性能至关重要或需要实时应用程序的情况下的适用性。

使用new和delete时可能发生的一些错误是：

对象（或内存）泄漏：使用new分配对象，而忘记删除该对象。

过早删除（或悬挂引用）：持有指向对象的另一个指针，删除该对象，然而还有其他指针在引用它。

双重删除：尝试两次删除一个对象。

通常，范围变量是首选。 但是，RAII可以用作new和delete的替代方法，以使对象独立于其范围而存在。 这种技术包括将指针分配到在堆上分配的对象，并将其放在句柄/管理器对象中。 后者具有一个析构函数，将负责销毁该对象。 这将确保该对象可用于任何想要访问它的函数，并且该对象在句柄对象的生存期结束时将被销毁，而无需进行显式清理。

来自C ++标准库的使用RAII的示例为std :: string和std :: vector。

考虑这段代码：


void fn(const std::string& str)
{
    std::vector<char> vec;
    for (auto c : str)
        vec.push_back(c);
    // do something
}
当创建vector,并将元素推入vector时，您不必担心分配和取消分配此类元素内存。 vector使用new为其堆上的元素分配空间，并使用delete释放该空间。 作为vector的用户，您无需关心实现细节，并且会相信vector不会泄漏。 在这种情况下，向量是其元素的句柄对象。
标准库中使用RAII的其他示例是std :: shared_ptr，std :: unique_ptr和std :: lock_guard。

该技术的另一个名称是SBRM，是范围绑定资源管理的缩写。

现在，我们将上述读取文件例子，进行修改：


#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <bits/unique_ptr.h>

using namespace std;
unique_ptr<vector<string>> read_lines_from_file(string &file_name) {
    unique_ptr<vector<string>> lines(new vector<string>);
    string line;

    ifstream file_handle (file_name.c_str());
    while (file_handle.good() && !file_handle.eof()) {
        getline(file_handle, line);
        lines->push_back(line);
    }

    file_handle.close();

    return lines;
}
int main(int argc, char* argv[]) {
    // get file name from the first argument
    string file_name (argv[1]);
    int count = read_lines_from_file(file_name).get()->size();
    cout << "File " << file_name << " contains " << count << " lines.";

    return 0;
}

RAII是一种很有前途的模式，但由于没有一些奇怪的解决方法，它根本无法用于堆分配的对象，因此在C ++中会受到影响。 因此，在90年代出现了垃圾收集语言的爆炸式增长，旨在使程序员生活更加愉快，即使以性能为代价。

RAII总结如下：

资源在析构函数中被释放

该类的实例是堆栈分配的

资源是在构造函数中获取的。
