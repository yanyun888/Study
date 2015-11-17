
#proC程序简介
##什么是pro程序
通过在过程化编程语言中，嵌入sql语句开发出的应用程序叫做pro程序。
宿主语言：sql语言所嵌入的语言
pascal

##为什么要有proc/proc++
让c或c++这种高效的语言 成为访问oarcle数据库的工具。proC是oracle公司开发的。
Java主要做的是web应用
proC是访问oracle数据的技术

##如何编写运行一个c程序
1. 编写源代码 vi XXX.c
2. 编译 gcc -c XXX.c
3. 链接 gcc XXX.o
4. 运行 ./a.out
 
##如果编写一个proC程序
1. 编写源代码 vi XXX.pc
2. 预编译 (把pc文件转换成c文件) proc XXX.pc
3. 编译链接 gcc XXX.c -lclntsh (linux unix)
           gcc XXX.c -lorasql10 (windows)
4. 运行 ./a.out

exec sql connect: 存放用户名密码的变量
exec sql connect connect:用户名变量 identified: 密码变量;

exec sql commit work release;
exec sql rollback work release;

#宿主变量
既能在sql语句中使用 又能在宿主语言中使用的变量叫宿主变量；桥梁作用的变量。

#宿主变量的类型
char var
char var[n] 定长字符串 如char var[10]
float
int
long
double
varchar var[10]


##定长字符串和变长字符串
172.30.2.20
###定长字符串

###变长字符串
需要把char类型变成varchar
在sql语句中要像普通的变量一样去使用，在宿主语言中要使用变量名.arr来获取数据
注意垃圾值问题，处理拉圾值的方法
- 初始化字符串为空
- 变量名.len 数据的实际长度
var_name.arr[var_name.len]='\0';

###使用proc的预编译选项
proc char_map=charz 默认字符映射 会把char数组处理成定长字符串 空格补齐\0结尾
char_map=string 会把char数据 处理成变长字符串，并自动\0结尾 通用话处理，影响范围太大

###和C++相关的预编译选项
proc 
oname输出文件名默认是.c，推荐以.cpp结尾
parse解析方式 默认是c的full方式
    parse=partia 严格的c++检查 不推荐使用
    parse=none 推荐使用
code代码风格 默认是c的ansi_C --美国国家标准信息交换码
    code=cpp 是c++的风格

要求 把宿主 变量仿如申明区
exec sql begin declare section;
exec sql end delcare section;

gcc ***.cpp -lclntsh -lstdc++
g++ ***.cpp -lclntsh

###和PL SQL调用相关的预编译选项
sqlcheck=semantics
userid=用户名/密码

###宿主变量的使用注意事项
- 宿主变量要放入申明区，这样可以避免系统或者语言的差异
- 宿主变量可以使用指针，但需要提前分配内存，特例，
    char *passwd = "openlab/open123";
    用的时候直接写passwd实现；

- DDL中不能使用宿主变量
```
char table_name[30]="test1506"；
exec sql drop table table_name; //这里删除的不是test1506 而是table_name
```
- 在除了DDL之外的sql中使用宿主变量，要在变量名前加冒号


##指示变量
###概念
当数据库中的字段值 赋值给宿主变量时，赋值的状态可以通过指示变量获得
`==0`   赋值正常
`==-1`  数据库中的字段值是空值NULL
`>0`    截断赋值 尽量避免这种情况


###语法
指示变量 必须是short类型
exec sql select 字段名 into :宿主变量:指示变量 from 表名 where 条件;
exec sql select 字段名 into :宿主变量 indicator:指示变量 from 表名 where 条件;

使用proc 链接数据库 然后把s_emp 表中 id=1的manager_id 赋值给一个宿主变量，并且指示赋值的状态。

##数组变量
###数组变量的使用注意事项
proc中只支持一维数组，字符除外
proc中不支持数组指针
proc中数组的最大元素个数 32767
在select 语句中使用数组时，只要给书数组的名字，不要给下标。

**把s_emp表中的 id first_name salary 分别放入数组中，然后后输出个三个数组的值**

int ids[50]
char names[50][30]

sqlca.sqlerrd[2] sql语句影响的行数
##sqlca通信区
sqlca通信区，本质上就是一个全局结构体，这个结构体中有一些字段可以记录sql语句的执行信息。
每次执行一次sql就会自动把这个结构体中的字段更新一遍，所以要获得sql语句的执行信息要执行完sql之后
立即获取，否则会被下一次sql覆盖掉。

###可以从sqlca中获取哪些信息呢？
sqlca.sqlerrd[2]  sql语句影响的行数
sqlca.sqlcode     sql语句的执行状态，
    `==0`  表示执行正常，
    `> 0`  表示执行出错(一般是违反了约束)
    `< 0`  表示网络错误 或 数据库管理系统错误
    
sqlca.sqlerrm.sqlerrmc  (sql error message/ sql error message content)
    content最多记录70个字符


    
    




















