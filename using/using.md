改变访问性

class Base{
public:
 std::size_t size() const { return n;  }
protected:
 std::size_t n;
};
class Derived : private Base {
public:
 using Base::size;
protected:
 using Base::n;
};
类Derived私有继承了Base，对于它来说成员变量n和成员函数size都是私有的，如果使用了using语句，可以改变他们的可访问性，如上述例子中，size可以按public的权限访问，n可以按protected的权限访问。


函数重载
在继承过程中，派生类可以覆盖重载函数的0个或多个实例，一旦定义了一个重载版本，那么其他的重载版本都会变为不可见。

如果对于基类的重载函数，我们需要在派生类中修改一个，又要让其他的保持可见，必须要重载所有版本，这样十分的繁琐。

取代typedef
C中常用typedef A B这样的语法，将B定义为A类型，也就是给A类型一个别名B

对应typedef A B，使用using B=A可以进行同样的操作。


私有继承 vs 公有继承的区别
私有继承（private inheritance）和公有继承（public inheritance）在C++中有根本性的区别，主要体现在访问控制和设计意图上。

主要区别
特性	公有继承 (public)	私有继承 (private)
关系语义	"是一个" (is-a) 关系	"根据...实现" (implemented-in-terms-of) 关系
基类成员可见性	保持原有访问权限	所有基类成员变为私有
外部访问	可以通过派生类访问基类公有成员	不能通过派生类访问任何基类成员
设计意图	接口继承	实现继承
私有继承的特点
实现继承而非接口继承：

私有继承意味着"根据基类实现派生类"，而不是"派生类是基类的一种"

基类的公有和保护成员都变成派生类的私有成员

隐藏基类接口：

外部代码无法通过派生类对象访问基类的任何成员

如你示例中的using Base::f，可以有选择地重新暴露某些基类成员

典型使用场景：

当你想使用基类的实现但不希望暴露基类接口时

替代组合(composition)的另一种实现方式

需要访问基类保护成员或重写基类虚函数时

公有继承的特点
接口继承：

表示"派生类是基类的一种"的is-a关系

基类的公有接口成为派生类接口的一部分

保持访问权限：

基类的public成员在派生类中仍是public

protected成员仍是protected

典型使用场景：

建立真正的继承层次结构

需要多态行为时

希望外部代码能使用基类接口操作派生类对象时