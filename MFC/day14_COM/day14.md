
# COM组件-ActiveX控件的应用(MFC的第二部分)
组件的使用在逐渐减少，组件的引入可以改善软件的架构，学会使用COM组件即可。

<!-- MarkdownTOC -->

- 1 概念
- 2 ActiveX控件的开发、注册、测试、和使用
    - 2.1 使用MFC的向导开发ActiveX控件
    - 2.2 在Ctrl类的OnDraw函数中完成控件的绘制
    - 2.3 在第一个接口中添加方法和属性DMcd
    - 2.4 在第二个接口中添加事件 DMcdEvents，AddEvent
    - 2.5 控件的注册
    - 2.6 控件的测试
    - 2.7 控件的使用
    - 2.8 Windows Media Player 控件的使用
    - 2.9 WTL控件(Windows template library)
- 3 COM的数据类型
    - 3.1 BSTR-COM的字符串类型
    - 3.2 VARIANT-COM的可变类型

<!-- /MarkdownTOC -->

## 1 概念
- ActiveX控件
    + 基于COM技术的，可以被多种不同计算机语言开发的程序所使用的控件。
    + *.ocx 文件后缀
- COM组件
    + Component Object Model，组件对象模型，一个较小的二进制文件，通过COM接口对外提供服务。
- COM接口
    + 是一组纯虚函数的集合，可以认为COM接口是纯虚类。
    + 接口只是功能的描述，不包括功能的具体实现。更抽象，不易发生变化。

## 2 ActiveX控件的开发、注册、测试、和使用
### 2.1 使用MFC的向导开发ActiveX控件

*** 使用`MFC ActiveX Control Wizard` ***

1. 第一个接口
    + 用来添加控件的属性和方法。
2. 第二个接口
    + 用来添加控件的事件。
3. Ctrl类
    + 在该类的OnDraw函数中绘制控件的外观。
4. App类
    + 与其他程序的相同
5. PropertyPage类
    + 设置控件的属性

注册ActiveX控件，在开发环境中已经完成了再当前机器的注册

### 2.2 在Ctrl类的OnDraw函数中完成控件的绘制

### 2.3 在第一个接口中添加方法和属性DMcd
- 添加`SetNumbers(int x,int y)`，计算并显示结果
- 添加
    + 外部名称和内部名称可以是不同的，但是一般会约定会写成相同的。
    + 内部实现功能，外部暴露接口。
### 2.4 在第二个接口中添加事件 DMcdEvents，AddEvent
- 事件 分为 库存事件 和 用户自定义事件。
    + 库存事件是自动通知的，用户自定义事件需要手动通知。
    +
### 2.5 控件的注册
- 使用VC6.0开发组件时，当编译程序时，自动完成控件的注册。
- 微软提供了工具：regsvr32.exe，完成控件的注册。
    + 控件注册：在运行框中输入`regsvr32 组件的文件路径`
    + 控件卸载：在运行框中输入`regsvr32 -u 组件的文件路径`
`regsvr32 F:\Git\Study\MFC\day14_COM\Mcd\Debug\Mcd.ocx`
- 控件的注册 - 将控件的信息写入了注册表
    + 控件的信息主要包括控件ID和控件所在文件的路径
    + 控件ID需要独一无二，ODL文件的重要性。
    + GUIDGEN.EXE 能够生成 独一无二的uuid
    + 在注册表中能够找到控件注册的信息，控件一旦注册使用后，就不要修改控件的文件路径。
        如果需要修改，必须重新注册。
- 控件的卸载 - 将控件的信息从注册表中删除

### 2.6 控件的测试
- ActiveX Control Test Container，控件的测试工具，主要通过属性、方法和事件对控件进行测试。

### 2.7 控件的使用
- 添加ActiveX控件，和MFC控件的使用方式相同。
    + 在桌面程序中使用控件
    + 在Web程序中使用控件

### 2.8 Windows Media Player 控件的使用

### 2.9 WTL控件(Windows template library)
- Web 程序中使用的COM 控件，轻量级

## 3 COM的数据类型
### 3.1 BSTR-COM的字符串类型
- 创建字符串 `SysAllocString`
- 使用字符串
- 释放字符串 `SysFreeString`
- BSTR的封装类：
    + 使用封装类能够简化变量的操作，构造和析构
    + 微软的ATL封装类，CComBSTR  `#include <atlbase.h>`
        * ActiveX Template Library , 类名称 CComBSTR
    + C++库的封装类，`#include <comdef.h>`
        * 类名称_bstr_t

### 3.2 VARIANT-COM的可变类型
- 本质是一个结构体。
- VARIANT封装类
    + ATL库：CComBSTR
    + C++库：_variant_t 需要显示的指定long类型



