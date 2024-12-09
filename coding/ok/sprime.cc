/*
ID: hillary3
LANG: C++
TASK: sprime
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

bool prime (int a) {
    if (a < 2) return false;

    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }

    return true;
}

void sprime(int num, int len) {
    if (len == n && prime(num)) cout << num << endl;

    if (prime(num)) {
        for (int i = 1; i < 10; i += 2) {
            if (i != 5) sprime (10*num+i, len+1);
        }
    }
}
int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    cin >> n;

    sprime(2, 1); sprime(3, 1); sprime(5, 1); sprime(7, 1);
}