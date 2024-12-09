#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

ll n;
string s, temp;
vector<ll> loc;
set<ll> ans;

int ct(string s) {
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) ans++;
    }

    return ans;
}

int main() {
    cin >> n >> s;

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'F') loc.push_back(i);
    }

    for (ll i = 0; i <= 1 << loc.size(); i++) { 
        ll bit_str = i;
        temp = s;

        for (long long j = 0; j < loc.size(); j++) {
            if (bit_str & 1) temp[loc[j]] = 'B';
            else temp[loc[j]] = 'E';
            
            bit_str >>= 1;
        }

        ans.insert(ct(temp));
    }

    cout << ans.size() << endl; for (auto c : ans) cout << c << endl;
}