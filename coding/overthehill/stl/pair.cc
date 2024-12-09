#include <iostream>
using namespace std;

int main() {
//pairs
pair<int, string> x, y;
x = {3, "hillary"};

x > y, x < y, x == y; //can compare elements of the pair

x.first, x.second; //first/second of pair

make_pair(4, "abc");

}