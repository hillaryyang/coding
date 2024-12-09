/*
ID: hillary3
TASK: skidesign
LANG: C++                 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1010], cost = 1e9, c;

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort (a, a+n);

    int big = a[n-1], small = a[0];

    if (big - small <= 17) cout << 0 << endl;

    else {
        for (int i = 0; i <= 83; i++) {
            int l = i, r = i + 17, total = 0;

            for (int j = 0; j < n; j++) {
                if (a[j] >= r) c = (r - a[j]) * (r - a[j]);
                else if (a[j] <= l) c = (a[j] - l) * (a[j] - l);
                else c = 0;

                total += c;
            }

            if (total < cost) cost = total;
        }
        cout << cost << endl;
    }
}