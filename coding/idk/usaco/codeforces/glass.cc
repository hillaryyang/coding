//https://codeforces.com/contest/528/problem/A
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll w, h, n, d;
char c;

int main() {
    cin >> w >> h >> n;

    multiset<ll> s1, s2;
    set<ll> hcut, vcut;
    s1.insert(h); s2.insert(w);
    hcut.insert(0); hcut.insert(h); 
    vcut.insert(0); vcut.insert(w); 

    for (int i = 0; i < n; i++) {
        cin >> c >> d;

        if (c == 'H') {
            hcut.insert(d);
            auto it = hcut.find(d), a = it, b = it;
            ll nex = *(++a), prev = *(--b);
            //cout << nex << " " << prev << endl;

            s1.insert(nex - *it); s1.insert(*it - prev);
            s1.erase(s1.find(nex - prev));
        }

        else {
            vcut.insert(d);
            auto it = vcut.find(d), a = it, b = it;
            ll nex = *(++a), prev = *(--b);

            s2.insert(nex - *it); s2.insert(*it - prev);
            s2.erase(s2.find(nex - prev));
        }
        /*for (auto c : s1) cout << c << " "; cout << endl;
        for (auto c : s2) cout << c << " "; cout << endl;*/

        ll mx1 = *(s1.rbegin()), mx2 = *(s2.rbegin());

        //cout << mx1 << " " << mx2 << endl;

        cout << mx1 * mx2 << endl; 
    }
}