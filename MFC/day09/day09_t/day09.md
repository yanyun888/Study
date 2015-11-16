
文件操作


CFile file
file.SeekToBegin();

#一 MFC的文件操作
  1 相关类
  CFile类 - 封装了文件句柄和操作文件的API。
    2.4 设置/获取文件信息
    CFile::GetStatus/SetStatus

   
     CFileFind::

     根目录是没有"."和".."的，之有非根目录才有"."和".."


#二 序列化
   1 相关类
     CArchive类 - 归档类，提供具体的数据读写操作。可以使用它代替CFile::Read/Write函数。
     使用CArchive在操作数值的时候特别方便，并且可以指定缓存区大小。
   2 CArchive类的使用
    2.1 新建或打开文件 
    	CFile::Open
    2.2 文件读写
      2.2.1 定义CArchive对象，（构造函数的第一个参数是文件对象的地址）
      2.2.2 文件读写
           >> ,读操作
           << ,写操作
      2.2.3 关闭CArchive对象
           CArchive::Close();  //在文件读写操作中会强制将缓存区中的数据存入文件中








