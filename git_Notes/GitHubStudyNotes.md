Created Date:2015-09-26
看来需要考虑一下不同编码之间换行的问题了
[TOC]

#代码版本管理工具
CVCS上一代代码版本管理工具的优劣分析

##版本管理的概念
git版本管理的优势


##git基本操作

###初始化一个新的repository
```language=git
git add *.c
git commit -m 'initial project version'
```

###从现有的repository克隆到本地
```language=git
git clone git://github.com/schacon/grit.git
//为克隆的git起一个别名
git clone git://github.com/schacon/grit.git mygitname
```

###将本地代码推送到github服务器
- 使用`git push`进行推送，需要用户名和密码，这里获得的信息是本地repo和服务器的差异比较，通过控制台的提示，使用commit来完成git的真正提交。
- 使用`git status`查看本地repository的状态
- 使用`git commit -a`可以将已经跟踪的左右文件全部加推送到git服务器中

###使用.gitignore来设定需要忽略的文件类型

- 使用`git rm --cached `来仅仅停止对一个文件的追踪
- 使用`git mv `来移动一个文件


###git提交历史查询
使用`git log`查看修改的历史记录
使用`git log -2`来查看最近两条记录
使用`git log -p`来查看每次提交之间的差异


###git撤销
`git commit --amend
**需要注意**的是，撤销操作是不可逆的，进行这个操作要格外小心


###添加一个远程仓库
添加一个远程仓库并可以为该远程仓库起一个别名
`git remote add `
`git remote add newName https://github.com/SamsonWang/repoName.git`

###标签
给某一个版本的代码打标签
`git tag` 查看现有标签















