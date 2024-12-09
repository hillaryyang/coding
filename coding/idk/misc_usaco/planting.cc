//http://www.usaco.org/index.php?page=viewproblem2&cpid=894
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    
    int n, a, b, mx = 0;
    vector<vector<int> > adj;
    cin >> n; 

    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b; adj[a].pb(b); adj[b].pb(a);
    }

    for (int i = 0; i < n + 1; i++) mx = max(mx, (int)adj[i].size());
    
    cout << mx + 1 << endl;
}