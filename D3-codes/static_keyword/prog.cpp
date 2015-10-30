#include <iostream>
#include "myclass.h"
using namespace std;

int main()
{
    myclass a;
    cout << myclass::get_num() << endl;
    myclass *b=new myclass;
    cout << myclass::get_num() << endl;
    delete b;
    cout << myclass::get_num() << endl;
}
