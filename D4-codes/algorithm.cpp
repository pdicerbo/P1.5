#include <iostream>
#include <algorithm>
#include <vector>

void print(int i)
{
	std::cout << " " << i;	
}


int main()
{
	std::vector<int> a;
	for (int i=0; i<5; i++)
		a.push_back(5-i);

	std::vector<int>::iterator it;
	it = std::find(a.begin(), a.end(), 3);
	if (it != a.end())
   		std::cout << "Element found in myvector: " << *it << '\n';
  	else
  		std::cout << "Element not found in myvector\n";


        for ( it = a.begin() ; it <= a.end(); it++)
                std::cout << *it << std::endl;
	

	std::sort (a.begin(), a.begin()+3);
	std::cout << " almost sorted " << std::endl;
        for ( it = a.begin() ; it <= a.end(); it++)
                std::cout << *it << std::endl;

	std::cout << " printing  " << std::endl;
	for_each (a.begin(), a.end(), print);
	std::cout << std::endl;
	return 0;
}
