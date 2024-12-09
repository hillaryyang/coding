#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int sum;

int divisors(int n) {
    int ct = 0; 
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) ct++;
    } return ct;
}

bool ok (int a) {
    if (divisors(a) == 20) return true;
    return false;
}

int main() {
    for (int i = 1; i <= 100; i++) {
        if (ok(20*i)) sum += 20 * i;
    }

    cout << sum/20 << endl;
}