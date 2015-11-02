
##异常(exception)
catch子句根据异常对象的类型，自上而下的顺序匹配，不是最优的匹配；因此对子类类型的异常
 捕获，不要放在对基类类型一场捕获的后面(子类会默认转换成父类)。

- 标准异常

###异常说明
返回类型 函数名(形参表) [const] throw(异常类型表){ ... }
函数的异常说明只是一种承诺，即表示该函数所抛出的异常不应该会超出说明的范围。如果该函数抛
 出异常说明以外的异常类型，该异常无法被此函数的调用所捕获，而被系统捕获，终止进程。
不写异常说明,表示可以抛出任何异常
空异常说明throw():表示不会抛出任何异常,或抛出的异常会被系统捕捉。

###构造函数中的异常
构造函数可以抛出异常，但如果在构造函数抛出异常，对象将会被不完整构造，这个对象其析构函数
 不会被调用。*后果是，有可能会造成内存泄露。*

###析构函数的异常
析构函数里语法上是允许抛出异常的，但是为了避免在异常中出现异常的情况，一般不建议在虚构函
 数设置异常。
仔细分析出现异常时，程序的执行路线。
*异常中的异常会直接被系统杀死(多个异常同时出现)*

函数如果是分开写的，异常说明是放在定义里，声明里，还是两者都要？
答：都要写，还要保证在定义和声明里严格一致(但是异常表的顺序可以不同)。

在多态时，派生类成员函数的抛出类型 要 _不多于_ 基类成员函数抛出的类型。


#I/O流
1 主要的I/O流类

IOS - 基类input/output stream
虚继承 - istream / ostream 
istrstream/ifstrstream   ofstrstream/ofstrstream     iostream

2格式化IO
1) 格式化函数
int ios::percision(int);//   设置浮点数精度函数
这里设置的只是现实的精度
int ios::width(int); //显示的域宽
char ios::fill(char);
long ios::setf(long);  //注意有互斥域

2)流控制符
`include <ioomanip>`
ios::left
ios::right
ios::internal // 内差对齐：符号左对齐，数据右对齐
setpercision(int); // 设置浮点数精度

setw(10)
setfill('~')
showops
left
showbase 
hex / dec / oct / bin
boolalpha  用字符串显示bool值 

2 字符串流
`include <strstream>`
有istrstream  ostrstream  strstream，主要用于操作内存

`include <sstream>`
这一套是比较新的一套 istringstream ostringstream stringstream


3 文件流
`include <fstream>`
读取文件ifstream
`ifstream(const char* filename,openmode mode); //缺省是wr可读可写`
写入文件ofstream
`ofstream(const char* filename,openmode mode);`
读写文件fstream
`fstream(const char* filename,openmode mode);`
mode 表示打开方式，默认是可读可写，

效率并没有C语言风格的高

- http://pdf7.tarena.com.cn/tts8_source/ttsPage/VIP/VIP_ESD00/STDCPP02/DAY03/COURSE/ppt.html
- http://pdf7.tarena.com.cn/tts8_source/ttsPage/VIP/VIP_ESD00/STDCPP02/DAY05/CASE/01/index.html


4 随机读写
1)设置读写指针的位置
`istream& istream::seekg(off_type offset,ios::seekdirorigin);`
`ostream& ostream::seekp(off_type offset,ios::seekdirorigin);`

orign 取值
ios::
ios::
ios::

2)获取读写指针的位置
`pos_type istream::tellg(void);`
`pos_type ostream::tellp(void);`














