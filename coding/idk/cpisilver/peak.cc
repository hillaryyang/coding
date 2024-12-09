//http://www.usaco.org/index.php?page=viewproblem2&cpid=896
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
const int N = 1e5 + 10;
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.f == b.f) return a.s > b.s;
    return a.f < b.f;
}

int main() {
    ll n, x, y, mx = -1, ct = 0; 
    vector<pair<ll, ll> > p;
    map<ll, ll> a;

    freopen("mountains.in", "r",stdin); freopen("mountains.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y; 
        p.pb(mp(x - y, x + y));
    }

    sort(p.begin(), p.end(), cmp);

    //for (auto i : p) cout << i.f << " "<< i.s << endl;
    
    for (auto i : p) {
        if (i.s > mx) {mx = i.s; ct++;}
    }

    cout << ct << endl;
}