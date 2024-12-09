//https://codeforces.com/contest/1851/problem/D
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define mp make_pair
const int N = 2e5 + 10;
using namespace std;

bool check(vector<ll> a, int n) {
    if (a.size() != n) return false;
    sort(a.begin(), a.end());
    
    for (int i = 1; i <= a.size(); i++) if (a[i - 1] != i) return false;

    return true;
}

int main() {
    ll t; cin >> t;

    while (t--) {
        ll n, x, sum = 0, val = 0, y = 0; vector<ll> s, dif;
        cin >> n;

        s.pb(0);
        for (int i = 0; i < n - 1; i++) {cin >> x; s.pb(x);}
        if (s.back() > n*(n+1)/2) {cout << "NO" << endl; continue;}
        if (s.back() != n*(n+1)/2) {
            s.pb(n*(n+1)/2);
            for (int i = 0; i < s.size() - 1; i++) dif.pb(s[i + 1] - s[i]);

            if (check(dif, n)) cout << "YES" << endl;
            else cout << "NO" << endl; 
            continue;
        }

        for (int i = 0; i < s.size() - 1; i++) dif.pb(s[i + 1] - s[i]);

        //for (int i : dif) cout << i << " "; cout << endl;

        map<ll, int> freq;
        for (int i : dif) freq[i]++;

        //for (int i = 1; i <= n; i++) cout << freq[i] << " "; cout << endl;

        bool ok = true; ll ct = 0;
        for (int i = 1; i <= n; i++) {
            if (freq[i] > 2) {ok = false; break;}
            else if (freq[i] == 2) ct++;
        }

        if (!ok || ct > 1) cout << "NO" << endl;
        else {
            if (ct == 0) {
                bool u[n + 3]; memset(u, 1, sizeof(u));
                for (ll i : dif) {
                    if (i <= n) u[i] = 0;
                    else val += i;
                }

                int cur = 0;
                for (int i = 1; i <= n; i++) {
                    if (u[i] && cur < 2) {sum += i; cur++;}
                }

                if (sum == val) cout << "YES" << endl;
                else cout << "NO" << endl;
            }

            else if (ct == 1) {
                for (int i = 1; i <= n; i++) if (freq[i] == 2) val = i;

                bool u[n + 3]; memset(u, 1, sizeof(u));
                for (ll i : dif) if (i <= n) u[i] = 0;

                //for (int i = 1; i <= n; i++) cout << u[i] << " "; cout << endl;

                int cur = 0;
                for (int i = 1; i <= n; i++) {
                    if (u[i] && cur < 2) {sum += i; cur++;}
                }

                if (sum == val) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}