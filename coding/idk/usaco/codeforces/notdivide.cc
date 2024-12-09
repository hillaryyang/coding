//https://codeforces.com/contest/1794/problem/B
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, x;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> a;
        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

        for (int i = 0; i < n; i++) if (a[i] == 1) a[i] = 2;

        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] % a[i] == 0) {a[i + 1]++;}
        }

        for (int i : a) cout << i << " "; cout << endl;
    }
}