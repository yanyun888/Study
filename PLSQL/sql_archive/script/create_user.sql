��һ��: ʹ��sys�û���¼oracle
C:\Documents and Settings\Administrator>sqlplus
Enter user-name: sys as sysdba
Enter password: 
�ڶ���:�����û�
SQL>create user test identified by test
default tablespace users
temporary tablespace temp;
������:���û���Ȩ
SQL>grant resource,connect to test;
���Ĳ�:���ӵ�test�û�
connect test
