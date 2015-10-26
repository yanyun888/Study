

#oraca 通信区
oraca通信区本质上也是一个全局结构体，可以通过oraca获得执行的sql语句，
这是sqlca的信息补充，

##如何获得执行的sql语句
*包含oraca通信区 
    exec sql include oraca;
*打开oraca (默认是关闭的)
    exec oracle option(oraca=yes);
*设置sql的保存标志 (默认是不保存的)
    oraca.orastxtf=0 默认不保存sql
    oraca.orastxtf=1 sql出错时保存
    oraca.orastxtf=2 sql出错或者sql出现警告时保存
    oraca.orastxtf=3 都保存
*获得执行的sql
    oraca.orastxt.orastxtc


#proc中如何使用sql
##如何使用select语句
在select语句前家exec sql
select语句要和into结合使用 把值放入宿主变量
exec sql select first_name into :name from s_emp where id=1;

##如何使用DML(insert delete update),TCL(commit rollback savepoint),DDL(create drop dalter)
在这写语句前 加exec sql
DDL中不能使用宿主变量
？DDL中不能使用宿主变量的逻辑推理过程是什么


#proc 中如如何调用PL SQL
连上数据库之后 在proc代码中出现以下代码
exec sql exec
    begin
      /* 这里需要遵循PL SQL的语法  */
    end;
end-exec;
加入预编译选项
SQLCHECK=SEMANTICS 调用plsql必须给的
userid=openlab/open123 在预编译时连接数据库确定存储过程是否存在与合法

写一个存储过程 设计两个整型参数 把两个参数的和存入第二个参数中。

create or replace procedure getSum(var_x number,var_y in out number)
is
begin
    var_y :=var_x+var_y;
end;

declare
 var_z number:=2;
begin
 getSum(1,var_z);
 dbms_output.put_line(var_z);
end;

写一个plsql中的函数， 设计两个整数参数 返回这两个参数的最大值。
写一个proc程序调用这个函数 验证函数功能，两个参数必须使用宿主变量


create or replace function getMax001(var_x number,var_x number)return number
is
begin
 if var_x>var_y then
   return var_x;
 else
   return var_y;
 end if;
end;


create or replace function getMax001(var_x number,var_x number)return number
is
begin
 if var_x > var_y then
   return var_x;
 end if;
   return var_y;
end;


#数据库的连接
exec sql connect: 用户名;
exec sql connect: 用户名 identified by :密码;
上面的连接方式是本地连接

连接的服务名是 echo $ORACLE_SID ，默认的名字是orcl，远程连接的时候会用到

远程连接涉及到的文件
$ORACLE_HOME/network/admin/tnsnames.ora
> $ORACLE_HOME oracle的安装目录

DB10 =
  (DESCRIPTION =
    (ADDRESS = (PROTOCOL = TCP)(HOST = 172.30.2.10)(PORT = 1521))
    (CONNECT_DATA =
      (SERVER = DEDICATED)
      (SERVICE_NAME = orcl)
    )   
  )
DB10就是172.30.2.10的机器上的数据库描述
using :远程数据库连接描述，可以区分不同的数据库
at: 标签名 可以区分具体的连接
只要在每个具体的sql操作前加exec sql at: 标签名

##使用database link的方式

exec sql create database link 连接名 connect to 用户名
   identified by 密码 using '远程数据库描述';
   
   从10数据库中 建立一个database link 到20数据库
create database link db10to20link connect to openlab
   identified by open123 using 'DB20';
   
select * from s_emp@db10to20link where id=1;

写一个proc程序连接本地数据库 连接本地数据库 本地数据库的用户名密码是scott/tigger 然后查询本地数据库中id=1的s_emp表中
的first_name 打印这个数据。然后使用database link  db10to80link 查询数据库中 s_emp 表中 id=1 的first_name 并打印。
最后使用database link db10to99link更新对应数据库中的s_emp 表 id=25的salary更新为25000。


#proc中的错误处理
##proc程序中的默认错误处理
proc默认是忽略的
事物控制

##通用错误处理(全局错误处理)
通知机制
exec sql whenever 条件  动作;
条件: sqlerror notfound(查询的数据未找到) sqlwarning
动作: do 函数名();
      do break;
      continue;  -- 继续运行程序
      goto 标签; -- 跳转到某个标签
      stop; --终止进程 exit
全局错误处理和局部错误处理同时存在的时候，会优先调用全局错误处理

#数据操作
##使用单个变量操作单行单列

exec sql select first_name into :var_name
    from s_emp where id=1;
    
##使用多个变量操作单行多列

##使用结构体操作单行多列
struct {

}emp;
##数组可以操作多行数据
##游标也可以操作多行多列



#proc 中的游标
##游标的使用步骤
定义游标
    exec sql declare 游标名 cursor for select语句;
打开游标
    exec sql open 游标名;
提取数据 处理数据
    exec sql fetch 游标名 into :结构题变量;
关闭游标
    exec sql close 游标名;
   
写一个proc程序 连接本地数据库 然后定义一个游标 用来存放s_emp 表中的id first_name salary
然后提取前两条数据打印 
   
   
##思考如何提取游标中所有的数据
故意出错机制 notfound
exec sql whenever notfound do break; //只能用在有循环的场景 如游标的提取
   
##滚动游标 scroll 
可以随机提取数据
exec sql declare 游标名 scroll cursor for select语句;

exec sql fetch last
exec sql fetch first
exec sql fetch prior
exec sql fetch next
exec sql fetch current
exec fetch relative n   相对的
exec fetch absolute n   绝对的

#动态sql
##第一种动态sql
不能是select语句 不能有占位符
exec sql execute immediate sqlstr;

##第二种动态sql
char sqlstr[100]="insert into s_dept values(:b0,:b1,:b2)";
/* 对于有占位符的要进行预处理  */
exec sql prepare s from :sqlstr;
exec sql execute s using :变量1:变量2:变量3;

##第三种动态sql
能且只能处理select语句 可以有占位符(多一次预处理，prepare s from)
char sqlstr[100] =" select id,first_name,salary from s_emp where id>:b0";
exec sql prepare ss from :sqlstr;
/* 声明一个游标 关联到ss */
exec sql delcare empcursor curosr for ss;
/* 打开游标时，传入实参  */
exec sql open empcursor using :id; //这里的id不能为确定的值，必须为变量
/* 一旦打开游标 则就是一个普通的游标 */
exec sql open empcursor using :id;









