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

    /*ll far;
    for (int i = 0; i < n; i++) {
        if (lev[i] != 0) {far = i; break;}
    }
    //cout << far << endl;*/

    ll ct = 0;
    for (int i = 0; i < n; i++) {
        //for (int l : lev) cout << l << " "; cout << endl;

        ct += abs(lev[i]); //cout << ct << endl;
        for (int j = i + 1; j < n; j++) lev[j] += (j - i + 1) * (-1 * lev[i]);
        lev[i] = 0;
    }

    cout << ct << endl;
}