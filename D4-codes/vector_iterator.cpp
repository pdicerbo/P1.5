#include <iostream>
#include <vector>

int main()
{
	std::vector<double> a;
	for (int i=0; i<5; i++)
		a.push_back( static_cast<double>(i));

	std::vector<double>::iterator myIt;
	for ( myIt = a.begin() ; myIt != a.end(); myIt++)
		std::cout << *myIt << std::endl;

	std::cout << "---" << std::endl;
	a.erase(a.begin(), a.begin()+2);

        for ( myIt = a.begin() ; myIt <= a.end(); myIt++)
                std::cout << *myIt << std::endl;
	
        std::cout << "---" << std::endl;
	myIt= a.begin()+1;
	std::cout << *(myIt + 2) << std::endl;
	std::cout << myIt[2] << std::endl;
	return 0;
}
