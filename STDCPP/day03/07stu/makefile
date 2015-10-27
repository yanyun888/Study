stu.out:main.o stu.o
	g++ main.o stu.o -ostu.out
main.o:07main.cpp
	g++ -c 07main.cpp -omain.o
stu.o:stu.cpp stu.h
	g++ -c stu.cpp

make clean:
	rm *.o

