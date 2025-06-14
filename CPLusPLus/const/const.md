1、const 常量和 #define 宏常量之间的区别可以概括为以下几点：

类型区别：

const 定义的常量具有数据类型，编译器可以进行类型检查，因此可以确保类型的正确性。

#define 宏定义没有类型，它只是简单的字符串替换，编译器不能进行类型检查。宏常量的类型是根据具体使用情况推导出来的，例如 #define FOURTY_TWO 42 会让 FOURTY_TWO 具有 int 类型。

内存存储：

const 定义的常量在运行时会有一份拷贝，其地址是固定的，且通常作为常量存储在程序的数据段中。

#define 定义的宏常量并不占用内存，它仅仅是一个编译时的替换，编译器会在每个使用该宏的地方直接插入其值，因此在内存中可能有多个拷贝。

编译时优化：

const 定义的常量有可能会被编译器优化为立即数（特别是在作为常量表达式时），这种优化能提高性能，避免在内存中存储额外的变量。

#define 定义的宏常量是一个纯粹的文本替换，虽然也能在多次使用时表现为立即数，但这种替换并没有类型安全和编译器优化。

使用场景：

const 定义的常量通常需要明确的类型，可以用于任何需要常量的场合，特别是与类型相关的操作中。

#define 定义的宏常量更多的是在宏定义的上下文中使用，它更适用于常见的常量表达式、条件编译等场景，但其不具备类型安全。

常量表达式：

const 常量只有在整数或枚举类型且通过常量表达式初始化时才能作为常量表达式。在其他情况下，它只是一个 const 限定的变量，并非真正的常量。

#define 宏常量本身并不区分常量和变量，它仅仅是字符串替换，不涉及类型或者初始化的限制。

总结：
类型安全：const 更强，提供类型检查。

内存占用：const 存在内存中，而 #define 只在编译时替换。

性能：const 可以更好地优化为立即数，通常能提升性能。

使用限制：const 需要具有类型且在某些情况下需要常量表达式，而 #define 更灵活，但不具备类型检查。

2、外部调用的时候，未被const修饰的变量不需要extern显式声明！而const常量需要显式声明extern，并且需要做初始化！因为常量在定义后就不能被修改，所以定义时必须初始化。

3、对于指向常量的指针，不能通过指针来修改对象的值，但是可以修改指针的值。
也不能使用void`*`指针保存const对象的地址，必须使用const void`*`类型的指针保存const对象的地址。
允许把非const对象的地址赋值给const对象的指针，如果要修改指针所指向的对象值，必须通过其他方式修改，不能直接通过当前指针直接修改。

4、使用const关键字进行说明的成员函数，称为常成员函数。只有常成员函数才有资格操作常量或常对象，没有使用const关键字说明的成员函数不能用来操作常对象。
const对象只能访问const成员函数,而非const对象可以访问任意的成员函数,包括const成员函数。