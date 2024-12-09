#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

ll n, a[20], b[20];
ll ans = 1;

ll taller(ll a) {
    ll t = 0;
    for (ll i = 0; i < n; i++) {
       if (b[i] >= a) t++;
    } return t;
}

int main() {   
    cin >> n;

    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];

    sort(a, a+n, greater<ll>());

    for(ll i = 1; i <= n; i++) ans *= taller(a[i-1]) - i + 1;

    cout << ans << endl;
}