#include <random>
#include <vector>
#include <iostream>

using namespace std;

template<typename num>
num get_random_number(num s, num e)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(s, e);
    return dis(gen);
};

template<typename num>
vector<num> get_random_vector()
{
    vector<num> vec;
    for (int i = 0; i < (int)get_random_number<num>(30,100); i++)
        vec.push_back(get_random_number<num>(0,1));
    return vec;
}


int main()
{
    vector<double> vec = get_random_vector<double>();
    {
    // loop fortran style:
    for (int i ; i<vec.size(); i++)
        cout << "fortran way of looping: " << vec[i] << endl;
        // suppose you don't know the size!?!?
    }
    {
    // use iterators
    vector<double>::iterator it = vec.begin();
    vector<double>::const_iterator eit = vec.end();
    for (;it != eit; ++it) 
        cout << "looping via iterator: " << *it << endl;
        // why dereferentiating??
    }
    {
    // use iterators
    auto it = vec.begin();
    auto eit = vec.end();
    for (;it != eit; ++it) 
        cout << "looping via iterator: " << *it << endl;
        // why dereferentiating??
    }   
    {
    // Range based iteration
    for (auto it : vec) 
        cout << "range based iteration: " << it << endl;
    }
    {
    // Range based iteration
    for (auto &it : vec) 
        cout << "range based iteration: " << it << endl;
    }

}
