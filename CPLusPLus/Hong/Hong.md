1、宏字符串
字符串化操作符（#）
在一个宏中的参数前面使用一个#,预处理器会把这个参数转换为一个字符数组，换言之就是：#是“字符串化”的意思，出现在宏定义中的#是把跟在后面的参数转换成一个字符串。

符号连接操作符（##）
##是一种分隔连接方式，它的作用是先分隔，然后进行强制连接。将宏定义的多个形参转换成一个实际参数名
注意事项：

（1）当用##连接形参时，##前后的空格可有可无。

（2）连接后的实际参数名，必须为实际存在的参数名或是编译器已知的宏定义。

（3）如果##后的参数本身也是一个宏的话，##会阻止这个宏的展开。

续行操作符（\）
当定义的宏不能用一行表达完整时，可以用”\”表示下一行继续此宏的定义。

4、在写代码的时候，通常可以采用{}块，表示完整性
#define fun() {f1();f2();}
if(a>0)
    fun();
// 宏展开
if(a>0)
{
    f1();
    f2();
};

5、内核中由于不同架构的限制，很多时候会用到空宏，。在编译的时候，这些空宏会给出warning，为了避免这样的warning，我们可以使用do{...}while(0)来定义空宏：

#define EMPTYMICRO do{}while(0)

6、如果你有一个复杂的函数，变量很多，而且你不想要增加新的函数，可以使用do{...}while(0)，将你的代码写在里面，里面可以定义变量而不用考虑变量名会同函数之前或者之后的重复。 这种情况应该是指一个变量多处使用（但每处的意义还不同），我们可以在每个do-while中缩小作用域，比如：
int fc()
{
    int k1 = 10;
    cout<<k1<<endl;
    do{
        int k1 = 100;
        cout<<k1<<endl;
    }while(0);
    cout<<k1<<endl;
}