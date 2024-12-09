//https://codeforces.com/problemset/problem/1859/C
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int t, n; cin >> t;

    while (t--) {
        cin >> n;

        int mx = 0, sum;
        
        for (int i = n/2; i < n; i++) {
            sum = 0;

            for (int j = i; j <= n; j++) if (j != (i + n)/2) sum += (j * (i + n - j));
            
            mx = max(mx, ((i - 1)* i *(2 * i - 1)/6) + sum);
        }

        cout << mx << endl;
    }
}