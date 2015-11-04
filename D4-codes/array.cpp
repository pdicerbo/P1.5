#include <iostream>
#include <array>

int main()
{

	std::array<double,5 > a;
	std::cout << a.size() << " " <<sizeof(a) << std::endl;
	std::cout << a.at(44) << std::endl;

	return 0;
}
