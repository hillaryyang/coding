//https://codeforces.com/contest/1669/problem/F
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, x; cin >> t;

    while (t--) {
        int mx = 0;
        cin >> n;
        vector<int> c(n);

        for (int i = 0; i < n; i++) {cin >> c[i];}

        int a = c[0], b = c[n - 1], l = 0, r = n - 1;

        while (l < r) {
            if (a < b) {
                l++; a += c[l];
            }

            else if (a > b) {
                r--; b += c[r];
            }

            else {
                mx = l + 1 + n - r;
                l++; r--; 
                a += c[l]; b += c[r];
            }
        }

        cout << mx << endl;
    }
}