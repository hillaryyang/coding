#include <iostream>
#include <cmath>
using namespace std;

int main() {
long long n; cin >> n;
long long sum = 0; 
for (long long i = 1; i <= 12; i++) {
    sum += n/(pow(5, i));
}
cout << sum << endl;
}