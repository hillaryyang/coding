//http://www.usaco.org/index.php?page=viewproblem2&cpid=1203
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second
using namespace std;

int n, x;
vector<int> a, b;
map<int, int> m;

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {cin >> x; a.pb(x);}
    for (int i = 0; i < n; i++) {
        cin >> x; b.pb(i + 1); m[x] = i + 1;
    }

    bool ok = true;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {ok = false; break;}
    }

    if (ok) {cout << 0 << endl; return 0;}

    //for (int i : b) cout << i << " "; cout << endl;
    for (int i = 0; i < n; i++) a[i] = m[a[i]];

    //for (int i : a) cout << i << " "; cout << endl;

    int ans = 1, last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > last) {last = a[i]; ans++;}
    }

    cout << n - ans << endl;
}