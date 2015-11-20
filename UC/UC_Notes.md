
# Unix C 复习

## 编译预处理指令
`#warning “版本错误”`
用于在预编译阶段报错，发出警告

`#pragma GCC dependency “01demo.c”`
用于提示某个文件被修改过，保证依赖关系成立

## UNIX下静态库与动态库的使用
### 静态库
- 生成静态库的方法
	+ 使用gcc 编译生成.o文件
	+ 使用ar -r libxx.a xx.o 命令生成 .a 文件
	
- 使用静态库的方法
	+ gcc main.c libxxx.a
	+ gcc main.c -lxxx -L 所在路径

### 动态库
- 生成动态库的方法
	+ 使用gcc 编译生成.o文件
	+ 使用gcc -shared xx.o -o xx.so 命令生成 .so 文件

- 使用静态库的方法
	+ 在编程时需要加`#include<dlfcn.h>`头文件
	+ 在编程时使用dlopen，dlsym，dlclose，dlerror函数使用动态库
	+ 在程序编译时需要加 -ldl参数
	+ 需要配置`LD_LIBRARY_PATH`环境
		配置方法：export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
		查看当前动态库环境 echo $LD_LIBRARY_PATH
		




