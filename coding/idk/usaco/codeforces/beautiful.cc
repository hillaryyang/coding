//https://codeforces.com/problemset/problem/1841/B
#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, x; cin >> n;

        cin >> x; cout << 1;

        bool ok = true;

        int fi = x, mn = x, mx = 1e9;

        for (int i = 1; i < n; i++) {
            cin >> x; 

            if (x >= mn && x <= mx) {mn = x; cout << 1;}
            else if (ok && x <= fi) {cout << 1; mn = x; mx = fi; ok = false;}
            else cout << 0;
        } cout << endl;
    }
}