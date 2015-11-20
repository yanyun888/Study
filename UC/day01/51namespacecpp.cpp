
#include <iostream>
namespace ns {
	int var = 10;
	void fun (void){
		int a = 10;
		std::cout << "a = " << a << std::endl;
	}
}

int var = 100;
int main(int argc, const char * argv[])
{
	int var = 200;
	std::cout << "var = " << var << std::endl;
	std::cout << "::var = " << ::var << std::endl;
	std::cout << "ns::var = " << ns::var << std::endl;
	return 0;
}
