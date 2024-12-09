//http://www.usaco.org/index.php?page=viewproblem2&cpid=643
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
#define lb lower_bound
#define ub upper_bound
const ll N = 5e4 + 10;
using namespace std;

ll n, k, x, ans = 0;
vector<ll> a, l(N), r(N), lm(N), rm(N);

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}
    sort(a.begin(), a.end());
    //for(int i : a) cout << i << " "; cout << endl;

    ll j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && a[i] - a[j] > k) j++;
        lm[i] = j;
    }

    //for (int i = 0; i < n; i++) cout << lm[i] << " "; cout << endl;

    //find l[i]s
    for (int i = 0; i < n; i++) {
        l[i] = i - lm[i] + 1;
        if (i != 0) l[i] = max(l[i], l[i - 1]);
    }

    j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (j >= 0 && a[j] - a[i] > k) j--;
        rm[i] = j;
    }

    //find r[i]s
    for (int i = n - 1; i >= 0; i--) {
        r[i] = rm[i] - i + 1;
        if (i < n - 1) r[i] = max(r[i], r[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, l[i] + r[i + 1]);
    }
    
    cout << ans << endl;
}