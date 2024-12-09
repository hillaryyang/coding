//https://codeforces.com/problemset/problem/1761/C
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<vector<int> > ans(n + 1);

        for (int i = 1; i <= n; i++) ans[i].push_back(i);

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1') {
                    for (int k : ans[i + 1]) {
                        //cout << k << " ";
                        if (find(ans[j + 1].begin(), ans[j + 1].end(), k) == ans[j + 1].end()) ans[j + 1].push_back(k);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i].size() << " ";
            for (int j : ans[i]) cout << j << " "; cout << endl;
        }
    }
}