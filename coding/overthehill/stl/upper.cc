#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main() {

int b[] = {1, 2, 4, 5, 6};

int t = lower_bound(b, b + 5, 3) - b; //greater than or equal to
//cout << *p << endl; outputs 4

int s = upper_bound(b, b + 5, 3) - b;

}