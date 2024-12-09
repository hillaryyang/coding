//http://www.usaco.org/index.php?page=viewproblem2&cpid=1203
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second
using namespace std;

bool works (int x, vector<int> a) {
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (sum < x) sum += a[i];
        else if (sum == x) sum = a[i];
        else return false;
    }

    if (sum == x) return true;
    return false;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n, x, sum = 0, mx = 0; vector<int> a, pos;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> x; a.pb(x); 
            sum += x; mx = max(mx, x);
        }

        bool ok = true;
        for (int i : a) if (i != a[0]) ok = false;
        if (ok) {cout << 0 << endl; continue;}

        //find the possible stack sums
        for (int i = mx; i <= sum; i++) if (sum % i == 0) pos.pb(i);

        //for (int i : pos) cout << i << " "; cout << endl;
        
        //loop over possibilities and check if it works: break if it does
        for (int i : pos) {
            if (works(i, a)) {
                cout << n - (sum/i) << endl; break;
            }
        }
    }
}