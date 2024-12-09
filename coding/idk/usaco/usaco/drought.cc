//http://www.usaco.org/index.php?page=viewproblem2&cpid=1181
#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

vector<int> h;
ll t, n, x;

int main() {
    cin >> t;

    while (t--) {
        bool ok = true;
        
        cin >> n; h.clear();
        for (ll i = 0; i < n; i++) {cin >> x; h.push_back(x);}

        //checks if they're all the same, if so then it's just 0
        bool aa = true;
        for (auto c : h) if (c != h[0]) {aa = false; break;}
        if (aa) {cout << 0 << endl; continue;}
        
        ll ct = 0;

        for (ll i = 0; i < n - 2; i++) {
            if (h[i] < h[i + 1]) {
                ll c = h[i + 1] - h[i];
                h[i + 1] = h[i]; h[i + 2] -= c;

                if (h[i + 2] < 0) {ok = false; break;}
                ct += (2 * c);
            }
        }

        for (ll i = n - 1; i >= 2; i--) {
            if (h[i - 1] > h[i]) {
                ll d = (h[i - 1] - h[i]);
                h[i - 1] = h[i]; h[i - 2] -= d;

                if (h[i - 2] < 0) {ok = false; break;} 
                ct += (2 * d);
            }
        }

        //if !ok or if first > second then impossible
        if (!ok || h[0] > h[1] || h[n - 1] > h[n - 2]) cout << -1 << endl;
        else cout << ct << endl;
    }
}