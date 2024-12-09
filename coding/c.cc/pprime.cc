/*
ID: hillary3
TASK: pprime
LANG: C++             
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 1e6 + 10;

int primes[N], ct;
bool st[N];

void init (int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[ct++] = i;
        for (int j = 0; primes[j] <= n/i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

bool check (int x) {
    string s = to_string(x);
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    } return true;
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    init (N-1);
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < ct; i++) {
        int p = primes[i];
        if (p >= a && p <= b && check(p)) cout << p << endl;
    }
}