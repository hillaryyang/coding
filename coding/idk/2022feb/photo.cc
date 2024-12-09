//http://www.usaco.org/index.php?page=viewproblem2&cpid=1203
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second
using namespace std;

int n, x;
vector<int> a, b;
bool used[(int)1e5 + 2];

int solve(vector<int> a, vector<int> b) {
    for (int i : a) cout << i << ' ';
    cout << endl;
    for (int i : b) cout << i << ' ';
    cout << endl;
    bool ok = true;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            // cout << i << " " << a[i] << ' ' << b[i] << endl;
            ok = false; break;
        }
    }

    if (ok) return 0;

    vector<int> c, d;
    for (int i : a) {
        if (i == b.back()) break;
        c.pb(i);
    } 

    memset(used, 0, sizeof(used));
    for (int i : c) used[i] = true;
    for (int i : b) if (used[i]) d.pb(i);

    //for (int i : c) cout << i << " "; cout << endl;
    //for (int i : d) cout << i << " "; cout << endl;
    //cout << (n - c.size() - 1) << endl;

    return (a.size() - c.size() - 1) + solve(c, d);
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}
    for (int i = 0; i < n; i++) {cin >> x; b.pb(x);}

    //solve(a, b);
    cout << solve(a, b) << endl;
}