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


int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    cin >> l >> n >> fj >> cow;

    temp[0] = 0;
    for (int i = 0; i < n; i++) cin >> temp[i + 1] >> t[i];

    for (int i = 1; i <= n; i++) hs[i - 1] = (fj - cow) * (temp[i] - temp[i - 1]);

    //for (int i = 0; i < n; i++) cout << hs[i] << " "; cout << endl;
    //for (int i = 0; i < n; i++) cout << t[i] << " "; cout << endl;

    vector<ll>stop; ll mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        //cout << t[i] << " " << t[i + 1] << endl;
        if (t[i] >= mx) {stop.pb(t[i]); mx = t[i];}
    }

    //for (ll i : stop) cout << i << " "; cout << endl;
    
    //ll idx = 0; //location in stop
    for (int i = 0; i < n; i++) {  
        cur += hs[i];  
        //cout << cur << " " << t[i] << " " << stop[idx] << endl;
        if (t[i] == stop.back()) {
            stop.pop_back(); tot += cur * t[i]; cur = 0;
        }
    }

    cout << tot << endl;
}