

desc s_emp; 用于查看表用有什么字段
简单select语句

select id,last_name,salary 
from s_emp
where id = 10;

多表连接(等值连接，非等值连接，外连接，自连接)

select s.id,s.last_name,d.name
from s_emp s,s_dept d
where s.dept_id = d.id;

select e.id,e.last_name,d.name
from s_emp e,s_dept d
where e.dept_id(+)=d.id;

外连接会有(+) 符号的出现

select s1.id, s1.last_name, s1.manager_id
from s_emp s1, s_emp s2
where s1.id = s2.manager_id;


分组查询
select dept_id,max(salary)
from s_emp
where dept_id < 50
having max(salary)>50;


DDL
建表语句
create table s_emp{
	id number(7,2) constraint s_emp_pk primary key,
	last_name varchar2(30) not null,
	gender varchar2(30) default 'w',
	dept_id number(5),
	constraint emp_dept_fk
	foreign key(dept_id)
	references s_dept(id) on delete set null;
};
注意:在建表语句中，每一行是用逗号隔开的。
	着重记忆建表约束的写法
外键约束后加on delete set null,
约束名的约定起名规则

create sequence se_emp;
序列一般用来生成主键，逐渐递增，不会重复
se_emp.nextval   /  se_emp.currval   用来对序列进行增加1的运算 ／用来获取序列的当前值

alter table
rename

Oracle的分页处理

select * from 
(select id,last_name,salary from s_emp
order by nvl(salary,0) desc)
where rownum<11;

oracle的分页要像下面这么写，为rownum起一个别名通过别名来判断
select * from(
select rownum row_id,id,last_name,salary from(
select id,last_name,salary from s_emp
order by nvl(salary,0) desc)
)where row_id between 5 and 8;

PL/SQL部分
set serveroutput on  将数据库的命令行输出打开












