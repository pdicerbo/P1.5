#include <iostream>
#include <map>

struct cmp_str
{

   bool operator()(std::string a, std::string b)
   {
      return a.compare(b);
   }

};

int main()
{
        std::map <std::string,std::string, cmp_str> phonebook;

        std::cout << phonebook.size() << std::endl;
        phonebook["Pinu" ]="555-424242";
        std::cout << phonebook.size() << std::endl;
        phonebook["Pinu" ]="555-242424";
        std::cout << phonebook.size() << std::endl;
        std::cout << phonebook["Pinu"] << std::endl;

        return 0;
}



