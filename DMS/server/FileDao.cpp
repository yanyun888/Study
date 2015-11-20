/*File Name: LogDao.h
**Author: 
**Version: 
**Created Time: 15/09/28-14:11  */
 

#include "FileDao.h"
#include <iostream>
using namespace std;

//
FileDao::FileDao(string const& path) throw (DBException){
	cout << "打开数据库开始..." << endl;
	m_ofs.open(path.c_str(),ios::app);
	if(!m_ofs){
		throw DBException("数据库文件无法打开");
	}
	cout << "打开数据库完成。" << endl;
}

FileDao::~FileDao(void){
	cout << "关闭数据库开始..." << endl;
	cout << "插入数据库完成。" << endl;
}
void FileDao::Insert(MLogRec const& log) throw (DBException){
	cout << "插入数据开始.." << endl;
	m_ofs << log <<endl;
	cout << "插入数据完成。" << endl;

}


