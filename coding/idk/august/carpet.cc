//https://codeforces.com/contest/1862/problem/A
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 5e6 + 10;
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        string s; 
        char c[30][30];

        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < m; j++) c[i][j] = s[j];
        }

        s = "akiv";

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (c[j][i] == s.back()) {
                    s.pop_back(); break;
                }
            }

            if (s.empty()) break;
        }

        if (s.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}