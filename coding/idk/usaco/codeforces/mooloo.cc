#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, k, d[(int) 1e5];
    cin >> n >> k;

    ll ans = k + 1;

    for (int i = 0; i < n; i++) cin >> d[i];
    
    for (ll i = 1; i < n; i++) {
        if (d[i] - d[i - 1] > k) ans += (k + 1);
        else ans += (d[i] - d[i - 1]);
    }

    cout << ans << endl;
}