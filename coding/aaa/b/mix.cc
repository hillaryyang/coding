/*
ID: hillary3
TASK: milk
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x, y, cost, amt;
vector <pair<int, int> > a;

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }

    sort (a.begin(), a.end());

    if (n == 0) cout << 0 << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < a[i].second; j++) {
            amt++; cost += a[i].first;

            if (amt == n) {cout << cost << endl; return 0; }
        }
    }
}