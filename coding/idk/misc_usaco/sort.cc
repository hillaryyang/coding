//http://www.usaco.org/index.php?page=viewproblem2&cpid=834
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
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    
    ll n, mn = 1e9, ct = 0; cin >> n;
    vector<ll> a, sup, temp; 
    map<ll, ll> m;
    a.resize(n); 

    for (int i = 0; i < n; i++) cin >> a[i];

    /*bool sorted = false;
    while (!sorted) {
        sorted = true;
        //cout << "MOO" << endl; 
        ct++;
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] < a[i]) {swap(a[i], a[i + 1]); sorted = false;}
        }
    }*/

    //find supp
    for (ll i : a) temp.pb(i); sort(temp.begin(), temp.end());
    temp.resize(n);
    for (int i = 0; i < n; i++) m[temp[i]] = i + 1;
    for (ll i : a) sup.pb(m[i]);

    for (int i = n - 1; i >= 0; i--) mn = min(mn, sup[i] - (i + 1));
    
    if (mn < 0) cout << 1 - mn << endl;
    else cout << mn + 1 << endl;
}