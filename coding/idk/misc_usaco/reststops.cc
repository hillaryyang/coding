//http://www.usaco.org/index.php?page=viewproblem2&cpid=810
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

ll l, n, fj, cow, hs[N], t[N], temp[N], ct, cur, tot;

vector<pair<ll,ll> > x;
int main() {
    for (int i = 0; i < 5; i++) {
        int a, b;
        cin >> a >> b; 
        x.pb(mp(a, b));
    }

    sort(x.begin(), x.end());

    for (auto i : x) cout << i.first << " " << i.second << endl;
}