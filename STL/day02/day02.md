
### 6. 函数模板的重载

针对变量和针对指针

选择何种类型是在第二次编译的时候做的，但是选择的范围是在第一次编译时确定的

针对与引用和非引用需要注意的问题：如果使用引用那么就都使用引用，如果不使用引用那么就都不使用引用

## 三、类模板
如果一个类的成员变量、成员函数、基类甚至于成员类型中包含参数化的类型，那么该类就是一个类模板。
### 1. 定义
`template<typename 类型形参1,typename 类型形参2, ...>`
`class 类模板名{}`
例如
`template<typename A,typename B,>`
`class`
### 2. 使用

类模板必须显示的使用，不能隐式使用(函数模板可以隐式使用)


### 3.两步实例化
          编译时          运行时
类模板 -> 实例化 -> 类 -> 实例化 -> 对象
         编译器做        处理器做
         
- 类模板中，只有那些被调用的那些成员函数(模板)才会被实例化(第二次编译)，因此如果对于某种类型不使用的成员函数，可以不满足其对类型的要求。
- 类模板并不代表一个具体类型，因此不能用类模板名定义变量，或者声明和引用指针，无论是在类模板的内部还是在其外部，任何需要使用类型的场合，都必须在类模板名后面加上“<>”表示的模板参数。
部分现代编译器也允许省略该模板参数表，以简化代码的书写。

- 类模板的成员变量，在该模板的每个实例化类中都有唯一的一份实例，并为该实例化类的所有对象所共享。         
静态成员变量 在数据区/BSS段
 
- 递归实例化
递归实例化之后生成多维数组。

运算符号最大扩展原则，在写尖括号时要加空格(此bug在C++11中已经解决)

类模板的特例化
```
template<>
class Comparator<char*>{
}
```
特化针对

类模板在满足足够多类型的同时，对一些特殊类型可能并不适用，或者不够优化，这是可以针对这些特殊类型编写该模板的特殊实现，谓之特化。
1)全类特化：将整个类模板针对某种成员类型具体化为特定的类
2)成员特化：将类模板中的部分成员函数针对某种类型具体化为普通成员函数
3)全类特化相当于另写一个类，除了类名要与模板名相关以外，可以完全不同；
但是成员函数特化版本和类模板中的

局部特化
- 类模板的局部特化
一方面为类模板指定特定类型的实现，另一方面又允许用户对部分模板参数自行指定，这样的特化形式就叫做局部特化或偏特化。
1)特化部分类型参数为具体类型
2)特化部分类型参数之间的特殊关系
3)特化部分类型参数所具有的特殊属性(指针，数组)
？？4)局部特化必须针对整个类模板，不能针对个别成员函数。函数模板不能局部特化。

- 模板的缺省参数
缺省参数要靠右写。
1) 类模板：允许为模板参数制定缺省值，但必须靠后。
2) 函数模板：C++98不允许为模板指定缺省参数，但是C++11允许为模板指定缺省参数
如果当隐式推断的类型和模板参素的缺省值不一致，以隐式推断的结构为准。无论是C++98还是C++11,函数模板的调用参数都可以带缺省值。
函数调用参数的缺省值，后面的参数不能引用前面参数作为其缺省值。
但是模板的参数后面的参数可以引用其前面的参数作为其缺省值。


智能指针的free和delete问题


函数参数的实例化过程在运行是
函数缺省值






