//http://www.usaco.org/index.php?page=viewproblem2&cpid=488
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set> 
const int N = 1e5 + 10;
#define ll long long
using namespace std;

int n, m;
char grid[51][51];
vector<pair<int, int> > ans;

bool hor (int i, int j) {
    return ((j == 0 || grid[i][j - 1] == '#') && grid[i][j + 1] == '.' && grid[i][j + 2] == '.');
}

bool ver (int i, int j) {
    return ((i == 0 || grid[i - 1][j] == '#') && grid[i + 1][j] == '.' && grid[i + 2][j] == '.');
}

int main() {
    freopen("crosswords.in", "r", stdin);
    freopen("crosswords.out", "w", stdout);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) grid[i][j] = s[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && (hor(i, j) || ver(i, j))) ans.push_back(make_pair(i + 1, j + 1));
        }
    }

    cout << ans.size() << endl;
    for (auto c : ans) cout << c.first << " " << c.second << endl;
}