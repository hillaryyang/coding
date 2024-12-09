#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define pb push_back
#define ll long long
using namespace std;

int main() {
    ll n, x; vector<ll> lev;
    
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> x; lev.pb(x);}

    ll ct = 0, cur = lev[0], dif = 0, sum = 0;

    for (int i = 0; i < n; i++) {
       // cout << cur << endl;
        sum += abs(cur); 
        dif += -1 * cur;
        cur = dif + lev[i + 1] - lev[i];
    }

    cout << sum << endl;
}