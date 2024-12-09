//https://codeforces.com/contest/1780/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int a, b, m, n, o, p, ct = 0;
        cin >> m >> n >> o >> p;

        if (m == 0) {cout << 1 << endl; continue;}

        ct += m + 2 * min(n, o)+ min(m + 1, abs(n - o) + p);

        cout << ct << endl;
    }
}