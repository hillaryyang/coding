//http://www.usaco.org/index.php?page=viewproblem2&cpid=856
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int n, s[101], e[101], b[101], u[1010], mx;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i] >> b[i];
        for (int j = s[i]; j <= e[i]; j++) u[j] += b[i];
    }

    //for (int i = 1; i < 15; i++) cout << u[i] << " "; cout << endl;

    for (int i = 0; i < n; i++) mx = max(u[s[i]], mx);

    cout << mx << endl;
}