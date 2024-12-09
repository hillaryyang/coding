//http://www.usaco.org/index.php?page=viewproblem2&cpid=857
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    int a[11], b[11];
    for (int i = 0; i < 10; i++) cin >> a[i];
    for (int i = 0; i < 10; i++) cin >> b[i];

    set<int> p;

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                for (int l = k + 1; l < 10; l++) {
                    p.insert(b[i] - a[k] + b[j] - a[l]);
                }
            }
        }
    }

   // for (int i : p) cout << i << " "; cout << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) p.insert(b[j] - a[i]);
    }

    p.insert(0);

    cout << p.size() << endl;
}