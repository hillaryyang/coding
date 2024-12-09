//http://www.usaco.org/index.php?page=viewproblem2&cpid=988
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

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int n, x; cin >> n;
    vector<int> a, b, c;

    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}

    for (int i = 1; i <= a[0]; i++) {
        b.pb(i);
        for (int j = 0; j < n - 1; j++) b.pb(a[j] - b[j]);

        for (int i : b) c.pb(i);
        sort(c.begin(), c.end());

        bool ok = true;
        for (int j = 0; j < n; j++) if (c[j] != j + 1) {ok = false; break;}

        if (ok) {
            for (int j = 0; j < n - 1; j++) cout << b[j] << " "; 
            cout << b[n - 1] << endl;
            break;
        }

        b.clear(); c.clear();
    }
}