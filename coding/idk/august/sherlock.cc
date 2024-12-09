//https://codeforces.com/problemset/problem/1857/F
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 1e5 + 10;
using namespace std;

int n, a[N]; bool st[N];

int main() {
    cin >> n;
    
    if (n < 3) cout << 1 << endl;
    else cout << 2 << endl;

    //find the primes from 2 to n + 1
    for (int i = 2; i <= n + 1; i++) {
        if (!st[i]) {
            a[i] = 1;
            for (int j = 2 * i; j <= n + 1; j += i) {
                st[j] = true; a[j] = 2;
            }
        }
    }

    for (int i = 2; i <= n + 1; i++) cout << a[i] << " "; cout << endl;
}