//http://www.usaco.org/index.php?page=viewproblem2&cpid=832
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define f first 
#define mp make_pair
using namespace std;

int n, m, k, c, p, x, order[101], t[101], l[101]; 
vector<int> h;
bool both[101];

bool ok(int a) {
    if (order[a] > 0) return false; order[a] = 1;
    l[1] = a;

    //cout << a << ": "; for (int i = 1; i <= n; i++) cout << order[i] << " "; cout << endl;
    //cout << "h: "; for (int i : h) cout << i << " "; cout << endl;

    int cur = 1; vector<int> temp; 
    for (int i : h) temp.pb(i);

    while (!temp.empty()) {
        if (!both[temp[0]]) {
            if (order[cur] == 0) {order[cur] = temp[0]; temp.erase(temp.begin());}
            else cur++;
        }
        else {cur = l[temp[0]]; temp.erase(temp.begin());}
    }

    /*cout << a << ": "; for (int i = 1; i <= n + 1; i++) cout << order[i] << " "; cout << endl;
    cout << "l: "; for (int i = 1; i <= n; i++) cout << l[i] << " "; cout << endl;*/

    vector<int> b;
    for (int i : h) b.pb(i); reverse(b.begin(), b.end());
    for (int i = 1; i <= n + 5; i++) {
        if (order[i] == b.back()) {
            b.pop_back();
            if (b.empty()) return true;
        }
    }

    return false;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {cin >> x; h.pb(x);}

    for (int i = 0; i < k; i++) {
        cin >> c >> p; order[p] = c; t[p] = c; l[c] = p;
    }

    //cout << "l: "; for (int i = 1; i <= n; i++) cout << l[i] << " "; cout << endl;

    //gets cows in both
    for (int i = 1; i <= n; i++) {
        for (int j : h) if (j == order[i]) both[j] = true;
    } for (int i : h) if (i == 1) both[1] = true;

    //for (int i = 1; i <= n; i++) cout << both[i] << " "; cout << endl;

    for (int i = 1; i <= n; i++) {
        if (ok(i)) {cout << i << endl; return 0;}
        for (int j = 1; j <= n; j++) order[j] = t[j];
    }
}