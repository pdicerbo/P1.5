#include <iostream>

int main(){

	int a=5;
        int &aRef=a;

	std::cout << " a = " << a << " aRef "  << aRef << std::endl;

	a=4;
	
	std::cout << " a = " << a << " aRef "  << aRef << std::endl;
	
	aRef=3;

	std::cout << " a = " << a << " aRef "  << aRef << std::endl;

	return 0;
}
