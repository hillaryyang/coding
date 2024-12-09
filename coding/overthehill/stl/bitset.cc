#include <iostream>
#include <bitset>
using namespace std;

int main() {
//bitset stuff
bitset<1000> a;
a[0] = 1;
a[1] = 1;

a.set(3); //sets all bits to true or sets one bit to value
a.reset(3); //resets bits

a.count(); //gives number of set bits
}