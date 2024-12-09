//https://codeforces.com/contest/1792/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

int main() {
    int t, n, x; cin >> t;

    while (t--) {
        cin >> n;
        
        if (n % 2 == 0) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            int low = (2 * n + 1) - ((n - 1)/2);
            //cout << low << endl;
            for (int i = 1; i <= 2 * n - low + 2; i++) {
                cout << i << " " << i + low - 2 << endl;
            }

            int f = 2 * n - low + 3;
            int dif = low + 1 - 2 * f;
            for (int i = f; i < f + n/2; i++) {
                cout << i << " " << i + dif << endl;
            }
        }
    }
}