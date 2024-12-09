//http://www.usaco.org/index.php?page=viewproblem2&cpid=920
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define mp make_pair
#define ll long long
#define pb push_back
const int N = 1e5 + 10;
using namespace std;

int n, m, x, y, ct, vis[N]; char a;
vector<vector<int> > s, d;
bool bad;

void dfs(int i, int val) {
    vis[i] = val;

    for (int j : s[i]) {
        if (vis[j] == 3 - val) bad = true;
        if (vis[j] == 0) dfs(j, val);
    }

    for (int j : d[i]) {
        if (vis[j] == val) bad = true;
        if (vis[j] == 0) dfs(j, 3 - val);
    } 
}

int main() { 
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    
    cin >> n >> m;

   s.resize(n + 1); d.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> x >> y;
        if (a == 'S') { s[x].pb(y); s[y].pb(x); }
        else { d[x].pb(y); d[y].pb(x); }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j : s[i]) cout << j << " "; cout << endl;
    }*/

    for (int i = 1; i <= n; i++) if (vis[i] == 0) {dfs(i, 1); ct++;} 

    if (bad) cout << 0 << endl;
    else {
        string ans = "1";
        for (int i = 0; i < ct; i++) ans += '0';
        cout << ans << endl;     
    }
}