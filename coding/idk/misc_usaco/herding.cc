//http://www.usaco.org/index.php?page=viewproblem2&cpid=918
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    ll n, x, mx = 0, mn = 2e9; vector<ll> a;
    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    //minimum possible
    for (int i = 0; i < n; i++) {
        //start at a[i]
        if (a[i] + n - 1 <= a.back()) {
            auto it = lower_bound(a.begin(), a.end(), a[i] + n);
            ll ind = it - a.begin() - 1, val = n - (ind - i + 1);
            
            //cout << i << " " << val << endl;

            if (val < mn) mn = val;
        }
    }
    if (a[n - 2] - a[0] == n - 2 && a[n - 1] - a[n - 2] > 2) mn = 2;
    if (a[n - 1] - a[1] == n - 2 && a[1] - a[0] > 2) mn = 2;


    //maximum possible outside
    //count the number of empty spaces from a[0] to a[n - 1]
    int empty = a[n - 1] - a[0] + 1 - n, small = min(a[1] - a[0] - 1, a[n - 1] - a[n - 2] - 1); 
    mx = empty - small;

    cout << mn << endl << mx << endl;
}