//https://codeforces.com/contest/1800/problem/C1
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll t, n, x; cin >> t;

    while (t--) {
        cin >> n;

        ll ans = 0;

        vector<ll> deck(n); 

        for (int i = 0; i < n; i++) {cin >> x; deck.push_back(x);}

        while (deck[0] == 0 && !deck.empty()) deck.erase(deck.begin());

        for (int i = 0; i < deck.size(); i++) {
            if (deck[i] == 0) {
                ll mx = 0;
                for (int j = 0; j < i; j++) mx = max(mx, deck[j]);
                for (int j = 0; j < i; j++) if (deck[j] == mx) {deck[j] = -1; break;}
                
                ans += mx; 
            }
        }

        cout << ans << endl;
    }
}