//https://codeforces.com/problemset/problem/1858/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

int main() {
    int t, n; cin >> t;

    while (t--) {
        cin >> n;

        bool a[(int) (1e5 + 10)]; memset(a, 1, sizeof(a));
        vector<int> p; p.push_back(1);

        for (int i = 2; i <= n; i++) {
            int cur = i; 
            while (cur <= n && a[cur]) {
                p.push_back(cur); a[cur] = 0; cur *= 2;
            }
        }

        for (int i = 2; i <= n; i++) if (a[i]) p.push_back(i);

        for (int i : p) cout << i << " "; cout << endl;
    }
}