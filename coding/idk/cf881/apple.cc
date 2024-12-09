//https://mirror.codeforces.com/contest/1843/problem/D
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
const int N = 2e5 + 10;
#define ll long long
using namespace std;

ll t, n, u, v, q, x, y, ct[N];
bool visited[N];
vector<vector<ll> > adj(N);

ll dfs (ll x) {
    if (adj[x].size() == 1 && x != 1) {ct[x] = 1; return ct[x];}

    visited[x] = true;
    for (int i : adj[x]) {
        if (!visited[i]) ct[x] += dfs(i);
    }

    return ct[x];
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < N; i++) adj[i].clear();
        memset(visited, false, sizeof(visited));
        memset(ct, 0, sizeof(ct));


        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v); adj[v].push_back(u);
        }

        dfs(1);

        cin >> q;
        while (q--) {
            cin >> x >> y;
            cout << ct[x] * ct[y] << endl;
        }
    }
}