#include <iostream>
#include <vector>
using namespace std;

/*to run have to use:
++ -std=c++11 -o <output file name> <source file name>.cpp */

int main() {
//vector define with:
vector<int> a;
vector<int> b[233]; 
//vector<int> a({1, 2, 3});

//vector functions
a.size();
a.empty(); //returns true if a is empty
a.front(); //first element
a.begin(); //pointer to the first element
a.back(); //last element
a.end(); //one past the last element (null)
//can also use a[0] 

//vectors with struct
struct Rec
{
    int x, y;
};
//vector<Rec> c;

//iterator
vector<int>::iterator it = a.begin();

//cout elements of array -> many ways!!!!!!!!
for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
cout << endl;

for (vector<int>::iterator i = a.begin(); i != a.end(); i++) cout << *i << " ";
cout << endl;
//same as above but with auto

//for (int i ; i < a.end(); i++) cout << *i << " ";
cout << endl;

//for (int x : a) cout << x << " ";
cout << endl;

//adds an element
a.push_back(4);
//for (auto x : a) cout << x << " "; //would have extra 4 at the end

//takes away an element
a.pop_back();
//for (auto x : a) cout << x << " "; //takes off the 3




}