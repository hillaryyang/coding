#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
int n;
ll t;
vector<pair<ll, ll> > hay;

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int d, b; cin >> d >> b;
        hay.push_back(make_pair(d, b));
    }

    hay.push_back(make_pair(t+1, 0));
    n++;

    ll bales = 0;
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ll d = hay[i].first;
        ll b = hay[i].second;
        bales += b;

        cout << "d = " << d << ", bales = " << bales << endl;
        ll interval = hay[i + 1].first - d;
        // cout << "interval = " << interval << endl;
        if (bales < interval) {
            ans += bales;
            bales = 0;
        }
        else {
            ans += interval;
            bales -= interval;
        }
    }

    cout << ans << endl;
}