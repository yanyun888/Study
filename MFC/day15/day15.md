MFC day15

<!-- MarkdownTOC autolink=true autoanchor=true brackets=round -->

- Windows平台上的数据库访问(MFC 的第三部分)
    - 1.数据库访问技术介绍
    - 2.ODBC类的使用
        - 2.1相关类
        - 2.2设置ODBC数据源
        - 2.3使用ODBC类访问数据库
    - 3.ADO的使用
        - 3.1ADO介绍
        - 3.2在项目中导入ADO组件
        - 3.3在使用组件的接口前，需要初始化COM库；并在使用后卸载
        - 3.4ADO组建的主要接口

<!-- /MarkdownTOC -->


# Windows平台上的数据库访问(MFC 的第三部分)
<a name="chapter1"></a>
## 1 数据库访问技术介绍
- ODBC - Open Database Connectivity , 微软开放式数据库互联。
    + 是一种用于访问数据库的API，MFC又将这组API封装成ODBC类。
    + 关系型数据库、非关系型数据库
- DAO - 基于ODBC，目前已被淘汰。
    + 用于方便访问Access数据库，
- OLE DB - 基于COM组件技术，提供了一组访问数据库的接口
    + OLE DB 使用难度比较大，所以并没有流行起来。
    + 优点是，执行效率比较高
- ADO - 基于OLE DB，对OLE DB进行封装
    + 简化OLE DB的使用，提供了一组更加简单的访问数据库的接口。
    + 成为Windows平台上广泛使用的技术之一。
- ADO.NET - 基于.NET平台的，一组访问数据库的类。
    + 是托管C/C++代码，虽然叫ADO，但是与ADO并没有必然的联系。
    + 托管代码 和 非托管代码

## 2 ODBC类的使用
### 2.1 相关类
- CDataBase类 - 主要功能是连接和关闭数据库。
- CRecordSet类 - 主要功能是对数据的操作。增删改查。
    需要包含头文件 `#include <afxdb.h>`
### 2.2 设置ODBC数据源
- ODBC 只能访问ODBC数据源，需要使用驱动建立数据库到ODBC数据源的连接
- 操作步骤：控制面板 - 管理工具 - 设置数据源ODBC
    + 用户DSN：只有本机用户能够使用
    + 系统DSN：远程登录的用户也能够使用
        * 设置好数据库名称 和 ODBC文件的位置。

### 2.3 使用ODBC类访问数据库
1. 打开ODBC数据源(链接数据库)
    + `CDatabase::Open`
2. 执行SQL语句
    + `CDatabase::ExecuteSQL`
3. 打开记录集
    + `CRecordset::Open`
4. 获取记录集中 字段的数量
    + `CRecordset::GetODBCFieldCount`
5. 获取记录集中 字段的信息
    + `CRecordset::GetODBCFieldValue`
6. 获取字段的值
    + `CRecordset::GetFieldValue`
7. 记录集的指针操作
    + `CRecordset::MoveNext`
    + `CRecordset::MovePrevious`
    + `CRecordset::MoveFirst`
    + `CRecordset::MoveLast`
    + `CRecordset::IsEof`
    + `CRecordset::IsBof`
8. 关闭记录集
    + `CRecordset::Close`
9. 关闭数据库
    + `CDatabase::Close`
- 在查找的时候，需要借助CRecorset作为桥梁。
- 在增删改的时候除了通过CRecordset，还可以直接向服务器发送SQL语句实现

## 3 ADO的使用

### 3.1 ADO介绍
- ADO 是独立于MFC之外的一个单独组件，对应的文件是msado15.dll
### 3.2在项目中导入ADO组件
- 在stdafx.h添加以下代码：
    `#import "文件路径" no_namespace rename("EOF","adoEOF")`
- 编译时，会在当前项目的debug文件下生成 msado15.tlh 和 msado15.tli 两个文件，说明导入成功。
### 3.3在使用组件的接口前，需要初始化COM库；并在使用后卸载
- 在App::InitInstance函数中：加入`CoInitialize`
- 在App::ExitInstance函数中：加入`CoUninitialize`

### 3.4 ADO组建的主要接口
Connection接口 - 功能与ODBC类的CDatabase相同
Recordset接口 - 功能与ODBC类的CRecordset相同
_将ADO组建的接口封装为C++类，使用类的成员函数代替ADO组件的接口函数。_

- **使用CAdoDatabase类封装Connection接口**
    + 连接数据库 `Open()`
```C
HRESULT Open (
    _bstr_t ConnectionString,    // 连接字符串
    _bstr_t UserID,                    // 登录ID
    _bstr_t Password,               // 登录密码
    long Options                      //选项，不指定时写 -1
```
    + 通过UDL文件配置生成   连接字符串
    + 关闭数据库 `Close()`
- **使用CAdoRecordset类封装Recordset接口**
    1. 打开表
```C
HRESULT Open (
    const _variant_t & Source,   //表名，存储过程名，SQL语句
    const _variant_t & ActiveConnection,    // 活动连接
    enum CursorTypeEnum CursorType,      // 游标类型
    enum LockTypeEnum LockType,            // 锁定类型
    long Options     // 选项 adCmdTable，adCmdStoredProc，adCmdText
                            // 为了标示第一个参数
);
```
> 枚举数据类型`CursorTypeEnum`
```C
enum CursorTypeEnum{
    adOpenUnspecified = -1,
    adOpenForwardOnly = 0,  // 静态的单向游标
    adOpenKeyset = 1,           // 键集游标，属于动态游标的一种
    adOpenDynamic = 2,       //  动态游标
    adOpenStatic = 3             // 静态游标(双向的)
};
```
    静态游标：当另一个用户对数据进行修改时，第一个是能够看到的。
    键集游标：也是动态游标，只能够看到对原有数据的修改，增删是看不到的。
    动态游标：能够实时反映出数据库中的增删改变化
枚举锁数据类型`LockTypeEnum`
```C
enum LockTypeEnum{
    adLockUnspecified = -1,
    adLockReadOnly = 1,      // 只读
    adLockPessimistic = 2,    // 悲观锁的锁定方式
    adLockOptimistic = 3,     // 乐观锁的锁定凡是
    adLockBatchOptimistic = 4   //批处理所的乐观锁锁定方式
};
```
只读：不能通过它进行数据库的修改
悲观锁与乐观锁的区别：上锁的时间不同
    2. 字段操作(Fields)
    Fields->GetCount();
    3. 字段的名称
    Fields->GetItem(nIndex)->GetName()
