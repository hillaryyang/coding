#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#define pb push_back
#define ll long long
using namespace std;

int main() {
    ll n, x, mn = 4e9+10, sum = 6;
    set<ll> a;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x; a.insert(x);
        mn = min(mn, x);
    }
    //cout << mn << endl;

    ll mxL = floor((double) mn/4);
    
    if (a.size() <= 3) {cout << mxL*(mxL+1)/2 << endl; return 0;}

    for (ll i = 4; i <= mxL; i++) {
        //cout << i << endl;
        set<int> re; bool ok = true;

        for (ll j : a) {
            //cout << j << " ";
            re.insert(j % i);
            //for (ll k : re) cout << k << " "; cout << endl;
            if (re.size() > 3) {ok = false; break;}
        }

        if (ok) sum += i; //cout << i << endl;
    }

    cout << sum << endl;
}