#include <iostream>
#include <vector>
using namespace std;

int n, b[1000], mx;
vector<pair<int, int> > ti;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t >> b[i];

        ti.push_back(make_pair(s, t));
    }

    for (int t = 1; t <= 1000; t++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (ti[i].first <= t && ti[i].second >= t) cur += b[i];
        }

        if (cur > mx) mx = cur;
    }

    cout << mx << endl;
}