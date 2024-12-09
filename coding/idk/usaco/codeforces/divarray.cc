//https://codeforces.com/contest/1828/problem/A
#include <iostream>
using namespace std;

int t, n, ans[201];

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i < n; i++) ans[i] = i + 1;

        int sum = (n-1)*(n+2)/2;

        for (int i = 1; i < 1000; i++) {
            if ((sum + i) % n == 0) {ans[0] = i; break;}
        }

        for (int i = 0; i < n - 1; i++) cout << ans[i] << " ";
        cout << ans[n - 1] << endl;
    }
}