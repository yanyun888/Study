a.out:main.o employee.o
	g++ main.o employee.o
main.o:main.cpp
	g++ -c main.cpp -omain.o
employee.o:employee.cpp employee.h
	g++ -c employee.cpp -oemployee.o

clean:
	rm *.o a.out
