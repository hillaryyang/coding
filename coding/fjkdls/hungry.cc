#include <iostream>
using namespace std;
typedef long long ll;

ll n, t, d[100000], b[100000], ct;

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> d[i] >> b[i];
    
    d[n] = t + 1;
    b[n] = 0;

    ll lastbales = b[0];

    for (int i = 1; i <= n; i++) {
        ll curbales = b[i] + max(lastbales - d[i] + d[i - 1], (ll) 0);
        ct += min(lastbales, d[i] - d[i - 1]);
        lastbales = curbales;
    }

    cout << ct << endl;
}