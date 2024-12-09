#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll n, t, x, y; cin >> n >> t;
    vector<ll> d, b;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x <= t) {d.push_back(x); b.push_back(y);}
    } d.push_back(t + 1); b.push_back(0);

    /*for (int i : d) cout << i << " "; cout << endl;
    for (int i : b) cout << i << " "; cout << endl;*/

    ll left = 0, tot = 0;

    for (int i = 0; i < d.size() - 1; i++) {
        if (b[i] < d[i + 1] - d[i]) {
            ll amt = d[i + 1] - d[i] - b[i];
            left = max((ll)0, left - amt);
        }

        else if (b[i] > d[i + 1] - d[i]) {
            left += b[i] - d[i + 1] + d[i];
        }

        tot += b[i];

        //cout << left << endl;
    }

    cout << tot - left << endl;
}