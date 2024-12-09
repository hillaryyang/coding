//https://codeforces.com/contest/1843/problem/E
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set> 
const int N = 1e5 + 10;
#define ll long long
using namespace std;

int t, n, m, qu, x, y, temp[N];
set <pair<int, int> > seg;
vector<int> q;

bool ok(int s, int e) {
    int c1 = 0, c2 = 0;
    for (int i = s - 1; i <= e - 1; i++) {
        if (temp[i] == 0) c1++;
        else c2++;
    }

    return c2 > c1;
}

bool check (int a) {
    //checks if a changes are sufficient to make any segment beautiful
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < a; i++) temp[q[i] - 1] = 1;

    for (auto i : seg) {
        if (ok(i.first, i.second)) return true;
    }
    return false;
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> m;

        while (m--) {cin >> x >> y; seg.insert(make_pair(x, y));}

        cin >> qu;
        q.resize(qu);
        for (int i = 0; i < qu; i++) cin >> q[i];

        int l = 1, r = q.size(), ans = 0;

        while (l <= r) {
            int mid = (l + r)/2;
            //cout << mid << endl;
            if (check(mid)) {r = mid - 1; ans = mid;}
            else l = mid + 1;
        }

        if (ans == 0) cout << -1 << endl;
        else cout << ans << endl;

        q.clear(); seg.clear();
    }
}