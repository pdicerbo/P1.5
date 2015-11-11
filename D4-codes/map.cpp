#include <iostream>
#include <map>

int main()
{
	std::map <std::string,std::string> phonebook;
	
	std::cout << phonebook.size() << std::endl;
	phonebook["Pinu" ]="555-424242";
        std::cout << phonebook.size() << std::endl;
        phonebook["Pinu" ]="555-242424";
        std::cout << phonebook.size() << std::endl;
	std::cout << phonebook["Pinu"] << std::endl;

	return 0;
}
