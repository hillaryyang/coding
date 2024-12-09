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
    int t; cin >> t;

    while (t--) {
        int n, m, ct; cin >> n >> m;
        vector<int> rocks;

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) grid[i][j] = s[j];
        }

        for (int i = 0; i < m; i++) {
            ct = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[j][i] == '*') ct++;

                else if (grid[j][i] == 'o') {rocks.push_back(ct); ct = 0;}
            } rocks.push_back(ct);
            
            if (rocks[0] == 0) rocks.erase(rocks.begin());

            //for (int j : rocks) cout << j << " "; cout << endl;
            
            int fr = -1, fo = -1;
            for (int j = n - 1; j >= 0; j--) if (grid[j][i] == 'o') {fo = j; break;}
            for (int j = n - 1; j >= 0; j--) if (grid[j][i] == '*') {fr = j; break;}

            if (fr > fo) {
                for (int k = n - 1; k > n - 1 - rocks[0]; k--) grid[k][i] = '*';
                
                int k = n - 1 - rocks[0];
                while (grid[k][i] != 'o' && k >= 0) {grid[k][i] = '.'; k--;}

                rocks.erase(rocks.begin());
            }

            for (int j = n - 1; j >= 0; j--) {
                if (grid[j][i] == 'o') {
                    for (int k = j - 1; k > j - rocks[0] - 1; k--) grid[k][i] = '*';

                    int k = j - rocks[0] - 1;
                    while (grid[k][i] != 'o' && k >= 0) {grid[k][i] = '.'; k--;}

                    rocks.erase(rocks.begin());
                }
            }

            rocks.clear();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << grid[i][j];
            cout << endl;
        }
    }
}    