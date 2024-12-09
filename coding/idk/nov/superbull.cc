//http://usaco.org/index.php?page=viewproblem2&cpid=531
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 2010;
using namespace std;

ll x, n, graph[N][N], weights[N], parent[N]; vector<ll> a; 
bool visited[N]; 

//returns index of the largest connected weight
ll f() {
    ll idx = -1, mx = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i] == false && weights[i] > mx) {mx = weights[i]; idx = i;}
    }

    return idx;
}

void maxtree(ll graph[N][N]) {
    for (int i = 0; i < n; i++) {visited[i] = false; weights[i] = 0;}

    weights[0] = 2e9; parent[0] = -1;

    for (int i = 0; i < n - 1; i++) {
        ll mx = f();
        visited[mx] = true;

        for (int j = 0; j < n; j++) {
            if (graph[j][mx] != 0 && visited[j] == false) {
                if (graph[j][mx] > weights[j]) {weights[j] = graph[j][mx]; parent[j] = mx;}
            }
        }
    }
}

int main() {
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) graph[i][j] = (a[i] ^ a[j]);
        }
    }

    maxtree(graph);

    ll ans = 0;
    for (int i = 1; i < N; i++) ans += graph[i][parent[i]];

    cout << ans << endl;
}