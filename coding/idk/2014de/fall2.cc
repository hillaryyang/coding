//https://codeforces.com/problemset/problem/1669/G
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set> 
#define ll long long
using namespace std;

char grid[51][51];

int main() {
    int t, n, m; cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) grid[i][j] = s[j];
        }

        for (int i = 0; i < m; i++) {
            int last = n;

            for (int j = n - 1; j >= 0; j--) {
                if (grid[j][i] == 'o') last = j;
                else if (grid[j][i] == '*') {
                    //cout << j << " " << last << endl;
                    grid[j][i] = '.'; grid[last - 1][i] = '*';
                    last--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << grid[i][j];
            cout << endl;
        }
    }
}
