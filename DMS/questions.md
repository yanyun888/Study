Questions:

在LogReader中，貌似存在逻辑上的错误：
我们先对wtmpx进行了备份，之后进行的读取操作有两个：读取登陆日志和读取备份日志
