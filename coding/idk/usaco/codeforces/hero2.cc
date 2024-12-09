//https://codeforces.com/contest/1800/problem/C2
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll t, n, x, ans;

int main() {
    cin >> t;

    while (t--) {
        vector<ll> deck(n), temp;
        deck.clear();
        cin >> n; ans = 0;

        for (int i = 0; i < n; i++) {cin >> x; deck.push_back(x);}

        while (deck[0] == 0 && !deck.empty()) deck.erase(deck.begin());

        for (int i = 0; i < deck.size(); i++) {
            if (deck[i] != 0) {
                //binary search for where to put deck[i]
                ll l = 0, r = max((ll)temp.size() - 1, (ll)0);

                ll loc;
                while (l <= r) {
                    // cout << "l " << l << " r " << r << endl;
                    int mid = (l + r)/2;
                    if (deck[i] >= deck[mid]) l = mid + 1; 
                    else r = mid - 1;
                }
                if (l >= temp.size()) temp.push_back(deck[i]);
                else temp.insert(temp.begin() + l, deck[i]);
                // for (int x : temp) cout << x << " ";
                // cout << endl;
                // cout << 38 << endl;
            }

            else {
                if (deck[i - 1] != 0) {
                    ll cur = i;

                    while (deck[cur] == 0 && cur < deck.size() && temp.size() != 0) {
                        ans += temp[temp.size() - 1]; temp.pop_back();
                        cur++;
                    }
                }
            }
        }

        cout << ans << endl;
        deck.clear(); temp.clear();
    }
}  

