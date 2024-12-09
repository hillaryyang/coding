//http://www.usaco.org/index.php?page=viewproblem2&cpid=1155
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
#define f first
using namespace std;

int main() {
    ll n, ans = 0; string s; vector<ll> c;
    cin >> n >> s;

    ll ct = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {c.pb(ct); ct = 1;}
        else ct++;
    } c.pb(ct); 

    //for (int i : c) cout << i << " "; cout << endl;
    //start on H, end on G
    //start on G, end on H
    ll ct1 = 0; 
    if (c.size() > 1) {
        //for (int i : c) cout << i << " "; cout << endl;

        ct1 += (max(c[0] - 1, (ll)0) + max(c[c.size() - 1] - 1, (ll)0));
        for (int i = 1; i < c.size() - 1; i++) {
            ct1 += max(2 * (c[i] - 1),(ll) 0);
        }
    }

    //start and end on same
    ll ct2 = 0; 
    for (int i = 1; i < c.size() - 1; i++) {
        if (c[i] == 1) ct2 += (c[i - 1] * c[i + 1]);
    }
    //cout << "c: "; for (int i : c) cout << i << " "; cout << endl;
    
    cout << ct1 + ct2 << endl;
}