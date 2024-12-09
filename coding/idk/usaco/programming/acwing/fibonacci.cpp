#include <iostream>
using namespace std;
//finds the nth fibonacci number
int fib[1000000];

int main() {
int n = 1000; //cin >> n;
fib[0] = 0;
fib[1] = 1;
for (int i = 2; i <= n; i++) {
    fib[i] = fib[i-2] + fib[i-1];
}

cout << fib[n] << endl;
}