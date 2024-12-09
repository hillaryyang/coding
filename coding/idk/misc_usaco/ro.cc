//http://www.usaco.org/index.php?page=viewproblem2&cpid=1325
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define mp make_pair
#define ll long long
#define pb push_back
using namespace std;

ll n, k, t; vector<ll> pos, a, temp;

int main() {
    cin >> n >> k >> t;
    pos.resize(n); a.resize(k);

    for (int i = 0; i < n; i++) pos[i] = i;
    for (int i = 0; i < k; i++) cin >> a[i];

    //perform one swap
    vector<ll> x;
    for (int i : pos) x.pb(i);
    for (int i = 0; i < k; i++) pos[a[i]] = x[a[(i - 1 + k) % k]];

    for (int i = 1; i < k; i++) {
        //startign from the second active position, go back to the first
        for (int j = a[i - 1] + 1; j <= a[i]; j++) temp.pb(pos[j]); 

        //modify temp
        int sz = temp.size(); vector<ll> ne; for (ll i : temp) ne.pb(i);
        for (int i = 0; i < sz; i++) temp[i] = ne[(i + ((t - 1) % sz) + sz) % sz];
        //for (int i = 0; i < temp.size(); i++) cout << temp[i] << " "; cout << endl;

        //put them back in in those positions
        for (int j = a[i - 1] + 1; j <= a[i]; j++) pos[j] = temp[j - a[i - 1] - 1];
        
        //for (int i : pos) cout << i << " "; cout << endl;
        temp.clear();
    }

    //do the first acitve position back to the last
    for (int i = 0; i <= a[0]; i++) temp.pb(pos[i]);
    for (int i = a[k - 1] + 1; i < n; i++) temp.pb(pos[i]);
    //for (int i = 0; i < temp.size(); i++) cout << temp[i] << " "; cout << endl;

    int sz = temp.size(), sh = (((t - 1) % sz) + sz) % sz; x.clear(); for (int i : temp) x.pb(i);
    for (int i = 0; i < sz; i++) {
        temp[i] = x[(i + sh) % sz];
    }    
    
    for (int i = 0; i <= a[0]; i++) pos[i] = temp[i];
    for (int i = a[0] + 1; i < temp.size(); i++) pos[a[k - 1] + i - a[0]] = temp[i];

    //for (int i : pos) cout << i << " "; cout << endl;

    //shift t to the right
    x.clear(); for (int i : pos) x.pb(i);
    sh = (((t - 1) % n) + n) % n;
    for (int i = 0; i < n; i++) pos[i] = x[(i - sh + n) % n];

    for (int i = 0; i < n - 1; i++) cout << pos[i] << " "; 
    cout << pos[n - 1] << endl;
}