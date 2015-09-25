
##git学习笔记

###安装git软件
ubuntu系统:sudo apt-get install git

###配置git的方法
生成本地的ssh密钥:ssh-keygen -t rsa -C"name@mail.com"
测试git是否连接成功ssh -T git@github.com

*将一个项目从git上复制下来*
$git clone https://github.com/username/projectname

*将文件添加到git中*
$git add filename.py 　　　　　　　　　　　#添加文件到版本库
$git commit -m 'add filename.py to src'　　#提交，产生版本记录，注意代码依然在本地

$vim README.md　　　　　　　　　　　　　　#修改Spoon-Knife中的README.md文件内容
$git commit -m 'modify the README.md' 　　　　#提交，产生版本记录，注意代码依然在本地
$git [remote] rm filename1.py　　　　　　　　#删除repo中的filename1.py文件
$git commit -m 'delete filename1.py' 　　　#提交，产生版本记录，注意代码依然在本地

*将修改提交到github上*
$git push origin 　　　　　　　　　　　#将修改提交到github上


