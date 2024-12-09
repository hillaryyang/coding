//http://www.usaco.org/index.php?page=viewproblem2&cpid=666
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define mp make_pair
#define ll long long
#define pb push_back
const int N = 10;
using namespace std;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    
    ll n, q, x, a, b, ct = 1; 
    vector<ll> temp; map<ll, ll> m;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {cin >> x; temp.pb(x);}

    sort(temp.begin(), temp.end());

    for (ll i : temp) {m[i] = ct; ct++;}

    while (q--) {
        cin >> a >> b;

        auto it1 = lower_bound(temp.begin(), temp.end(), a), it2 = upper_bound(temp.begin(), temp.end(), b);
        int x = it1 - temp.begin(), y = it2 - temp.begin();

        //cout << x << " " << y << endl;
        cout << y - x << endl;
    }


}