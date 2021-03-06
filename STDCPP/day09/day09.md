

封装，继承，多态

#多态(polymorphic)
如果基类中的某个成员函数声明为虚函数，那么子类中与该函数具有相同原型的成员函数就也是虚
函数，并且对父类中的版本形成覆盖。
这时通过指向子类对象的基类指针，或者通过引用子类对象的基类引用，调用虚函数，实际被执行
的是子类中的覆盖版本，而不是基类中的原始版本，这种语法现象被称为多态。

关键字：自动变虚，自动覆盖。

##覆盖的条件
1. 只有成员函数才能被声明虚函数;
2. 只有在基类中以virtual关键字修饰的成员函数才能作为虚函数被子类覆盖，
   而与子类中的virtual无关;
3. 虚函数在子类中的覆盖版本必须和该函数在基类中的原始版本拥有相同的
   签名(即函数名，形参表，常属性严格一致);
4. 如果基类中的虚函数返回的是基本类型数据，那么函数在子类的覆盖版本必须返回相同类型的数据;
5. 如果基类中虚函数返回类类型的指针或引用，那么允许子类的覆盖版本返
   回_子类_指针或引用(协变覆盖);
6. 覆盖版本可以出现在则类的公有，保护，私有的任何部分，不受访问控制属性影响。
* 返回值类型不同的函数不会形成覆盖，会形成_不正当关系_。                     


##多态的条件
1. 必须通过指针或引用调用虚函数
2. 调用虚函数的指针也可以是成员函数的this指针，this是一个指向子类对象的基类指针，
   同样也可以:只要它是一个指向子类对象的基类指针，同样可以表达出多态的特性。
3. 在构造和析构函数，只能绑定到基类版本，没有多态的特性


##纯虚函数、抽象类、纯抽象类
1. 形如 virtual 返回类型 函数名(形参表) = 0; 的函数被称为纯函数，表示数据抽象的行为。
纯虚函数  如virtual void draw(void)=0;
2. 如果一个类包含了至少一个纯虚函数，那么这个类就是抽象类；
   抽象类不能被实例化为对象。
3. 如果一个类除了构造和析构函数以外的所有成员函数都是纯虚函数，那么该抽象类就是一
   个纯抽象类(接口类)。
4. 如果一个子类没有覆盖其抽象基类中的全部纯虚函数，那么该子类就是一个抽象类。
   抽象基类的抽象属性可以被继承。

#虚函数表和动态绑定(研究一下多态的原理)
1. 虚表
编译器会为包含虚函数的类生成一张虚表，用来存放每个虚函数的地址，简称虚表。

2. 虚指针
编译器会为包含虚函数的类增加一个隐式的成员变量，用于存放虚表的首地址，
该变量被称为虚函数表指针，简称虚指针。

3. 所谓虚函数的覆盖，其本质就是用子类的虚函数地址，覆盖其基类虚表中的基类虚函数的地址。

4. 当编译器看到通过指针或者引用调用虚函数的语句时，不会生成有关函数调用的指令，而会用
   一段代码代替该语句，这段代码会在运行时被执行，完成如下操作:
    确定调用指针或引用目标的真实类型，从中找到虚指针，根据虚指针找到相应的虚表，并从中找
	到相应的虚表，并获取所调用虚函数的入口地址，根据虚函数的入口地址执行虚函数代码。
    这个过程在_运行_阶段完成，因此被称为动态绑定。

5. 动态绑定对性能的影响：动态绑定会增加内存的开销，虚函数的调用会增加时间的开销，虚函数
   不能被内联优化。
所以：如果没有多态的要求，最好不要使用虚函数。

#练习：
薪酬计算
员工：姓名，工号，等级
经理：绩效工资
技术员：研发津贴
销售员：提成比例

```
薪资=基本工资+绩效工资
基本工资=等级额度*出勤率
绩效工资的计算因职务而异：

	普通员工：基本工资的一半
经理：绩效奖金*绩效因数(输入)
技术员：研发津贴*工作小时数 *进度因数()
销售员：销售额度(输入) *提成比率
技术主管：技术员绩效工资 和 经理的绩效工资的 平均数
销售主管：销售人员的绩效工资 和 经理的绩效工资的 平均数

打印员工信息，输入必要数据，计算薪酬
```
















