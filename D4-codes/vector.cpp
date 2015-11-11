#include <iostream>
#include <vector>

int main()
{
	std::vector<double> a;
	a.push_back(7.0);

	std::cout << " a: size " <<  a.size() << " capacity " << a.capacity()  << std::endl;
	a.push_back(8.0);
        std::cout << " a: size " << a.size() << " capacity " << a.capacity()  << std::endl;

	std::vector<double> b;
	b.reserve(8);
        std::cout << " b: size " << b.size() << " capacity " << b.capacity()  << std::endl;

        std::vector<double> c(5);
        std::cout << " c: size " << c.size() << " capacity " << c.capacity()  << std::endl;
	std::cout << c[19000] << std::endl;

	return 0;
}
