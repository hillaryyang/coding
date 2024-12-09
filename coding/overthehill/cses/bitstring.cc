#include <iostream>
#include <cmath>
using namespace std;
#define x 1000000007;

int main() {
int n, result = 1; cin >> n;
for (int i = 0; i < n; i++) {
    result *= 2;
    result %= x;
}
cout << result << endl;
}