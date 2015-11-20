/*File Name:generator.c
**Author: 
**Version: 
**Created Time: 15/08/07-18:30  */
#include"generatorId.h" 

int generatorId(){
	int fd = open("num.dat",O_RDWR|O_CREAT,0644 );
	if(-1 == fd){
		perror("open data failed");
		return -1;
	}
	//对文件的大小进行判断，如果是空文件，则打印1
	int num;
	struct stat fileStat;
	int res = fstat(fd,&fileStat);
	if(-1 == res){
		perror("fstat");
	}
	if(fileStat.st_size < 4){
		num = 0;
	}
	else{
		res = read(fd,&num,sizeof(int));
		if(-1 == res){
			perror("read file failed");
			return -1;
		}
	}
//	printf("num = %d\n",num++);
	++num;
	//将数据保存在文件中
	res = lseek(fd,0,SEEK_SET);
	if(-1 == res){
		perror("lseek failed");
	}
	res = write(fd,&num,sizeof(int));
	if(-1 == res){
		perror("write failed");
	}
	return num-1;
}

