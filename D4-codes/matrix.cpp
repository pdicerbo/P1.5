#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector< vector<int> > vec;

	for (int i = 0; i < 10; i++) {
   		 vector<int> row; // Create an empty row
    			for (int j = 0; j < 20; j++) {
        			row.push_back(i * j); // Add an element (column) to the row
    				}
    		vec.push_back(row); // Add the row to the main vector
	}

	vector< vector<int> > vec2(4, vector<int>(4)) ;

        cout << vec[3][2] << endl;
	cout << vec2[3][2] << endl;
	return 0;
}
