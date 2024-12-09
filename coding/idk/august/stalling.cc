//http://www.usaco.org/index.php?page=viewproblem2&cpid=1085
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 2e5 + 10;
using namespace std;

int main() {
    ll n, x, ans = 1; vector<ll> a, b;

    cin >> n;
    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}
    for (int i = 0; i < n; i++) {cin >> x; b.pb(x);}

    sort(a.begin(), a.end(), greater<int>()); sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        int ct = 0;
        for (int j : b) if (j >= a[i]) ct++;

        ans *= (ct - i);
    }

    cout << ans << endl;
}