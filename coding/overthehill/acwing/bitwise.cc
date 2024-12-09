#include <iostream>
using namespace std;

int main() 
{
//AND
0 & 0 == 0;
0 & 1 == 0;
1 & 0 == 0;
1 & 1 == 1;

//OR
0 | 0 == 0;
0 | 1 == 1;
1 | 0 == 1;
1 | 1 == 1;

//NOT
~0 == 1;
~1 == 0;

//XOR (add without carry)
0 ^ 0 == 0;
0 ^ 1 == 1;
1 ^ 0 == 1;
1 ^ 1 == 0;

int a = 3, b = 6;
cout << (a ^ b) << endl;

//left and right shift
//a >> k = a / 2^k
//a << 1 = a * 2^k

int a = 13;
cout << (a >> 2 & 1) << endl; //gives the second digit of 13

//last 1 (1101000 --> 1000) is a&(~a+1) = a&(-a)
int a = 122121, b = -a, c = ~a + 1;

}