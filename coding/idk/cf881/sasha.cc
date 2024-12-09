//https://codeforces.com/contest/1843/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int x, n, ans = 0; cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

        sort(a.begin(), a.end());

        //for (int i : a) cout << i << " "; cout << endl;

        for (int i = 0; i < n/2; i++) ans += (a[n - 1 - i] - a[i]);
        
        cout << ans << endl;
    }
}