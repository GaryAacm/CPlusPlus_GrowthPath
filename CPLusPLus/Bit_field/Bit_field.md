“ 位域 “ 或 “ 位段 “(Bit field)为一种数据结构，可以把数据以位的形式紧凑的储存，并允许程序员对此结构的位进行操作。这种数据结构的一个好处是它可以使数据单元节省储存空间，当程序需要成千上万个数据单元时，这种方法就显得尤为重要。第二个好处是位段可以很方便的访问一个整数值的部分内容从而可以简化程序源代码。而这种数据结构的缺点在于，位段实现依赖于具体的机器和系统，在不同的平台可能有不同的结果，这导致了位段在本质上是不可移植的。

位域在内存中的布局是与机器有关的
位域的类型必须是整型或枚举类型，带符号类型中的位域的行为将因具体实现而定
取地址运算符（&）不能作用于位域，任何指针都无法指向类的位域

位域通常使用结构体声明， 该结构声明为每个位域成员设置名称，并决定其宽度：

struct bit_field_name
{
    type member_name : width;
};


Elements	Description
bit_field_name	位域结构名
type	位域成员的类型，必须为 int、signed int 或者 unsigned int 类型
member_name	位域成员名
width	规定成员所占的位数

位域的对齐¶
一个位域成员不允许跨越两个 unsigned int 的边界，如果成员声明的总位数超过了一个 unsigned int 的大小， 那么编辑器会自动移位位域成员，使其按照 unsigned int 的边界对齐。 例如：


struct stuff 
{
    unsigned int field1: 30;
    unsigned int field2: 4;
    unsigned int field3: 3;
};
field1 + field2 = 34 Bits，超出 32 Bits, 编译器会将field2移位至下一个 unsigned int 单元存放， stuff.field1 和 stuff.field2 之间会留下一个 2 Bits 的空隙， stuff.field3 紧跟在 stuff.field2 之后，该结构现在大小为 2 * 32 = 64 Bits。

这个空洞可以用之前提到的未命名的位域成员填充，我们也可以使用一个宽度为 0 的未命名位域成员令下一位域成员与下一个整数对齐。 例如:


struct stuff 
{
    unsigned int field1: 30;
    unsigned int       : 2;
    unsigned int field2: 4;
    unsigned int       : 0;
    unsigned int field3: 3; 
};
这里 stuff.field1 与 stuff.field2 之间有一个 2 Bits 的空隙，stuff.field3 则存储在下一个 unsigned int 中，该结构现在大小为 3 * 32 = 96 Bits。


“联合” 是一种特殊的类，也是一种构造类型的数据结构。在一个 “联合” 内可以定义多种不同的数据类型， 一个被说明为该 “联合” 类型的变量中，允许装入该 “联合” 所定义的任何一种数据，这些数据共享同一段内存，以达到节省空间的目的

“联合” 与 “结构” 有一些相似之处。但两者有本质上的不同。在结构中各成员有各自的内存空间， 一个结构变量的总长度是各成员长度之和（空结构除外，同时不考虑边界调整）。而在 “联合” 中，各成员共享一段内存空间， 一个联合变量的长度等于各成员中最长的长度。应该说明的是， 这里所谓的共享不是指把多个成员同时装入一个联合变量内， 而是指该联合变量可被赋予任一成员值，但每次只能赋一种值， 赋入新值则冲去旧值。


