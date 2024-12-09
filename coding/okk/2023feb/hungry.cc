#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll n, t, x, y, remain, total, last;
vector<pair<ll, ll> > d;

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        d.push_back(make_pair(x, y));
    }

    d.push_back(make_pair(t+1, 0));

    for (int i = 0; i < d.size(); i++) {
        //cout << d[i].first << " " << d[i].second << endl;

        total += d[i].second;

        remain -= d[i].first - last;
        last = d[i].first;

        remain = max((ll)0, remain) + d[i].second;
    }

    cout << total - remain << endl;
}