explicit(显式)关键字那些事
explicit 修饰构造函数时，可以防止隐式转换和复制初始化
explicit 修饰转换函数时，可以防止隐式转换，但按语境转换除外

在 C++ 中，explicit 是一个关键字，用于修饰类的单参数构造函数或转换运算符，以防止编译器进行隐式的类型转换。它的主要作用是让类型转换更加明确，避免意外的隐式转换导致的潜在问题。