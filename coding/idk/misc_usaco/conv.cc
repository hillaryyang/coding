//http://www.usaco.org/index.php?page=viewproblem2&cpid=858

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;

ll n, m, c; vector<ll> t;

bool check (ll w) {
    ll seats = c, bus = 1, f = t[0], dif = 0; 

    for (int i = 0; i < n; i++) {
        if (i != 0) dif += (t[i] - t[i - 1]);
        //start a new bus
        if (seats == 0 || dif > w) {
            bus++; seats = c; f = t[i]; dif = 0;
        }

        seats--;
    }

    if (bus > m) return false; 
    return true;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n >> m >> c; 
    t.resize(n);

    for (int i = 0; i < n; i++) cin >> t[i];
    sort(t.begin(), t.end());

    //binary search on w
    ll l = 1, r = 1e9, mid;
    while (l < r) {
       mid = l + (r - l)/2;

       if (check(mid)) r = mid;
       else l = mid + 1; 
    }
    //cout << check(4) << " "<< check(5) << endl;
    
    cout << l << endl;
}