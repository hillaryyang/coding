#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    cin >> n;

    int ans = n;
    vector<pair<int, char> > c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i].second >> c[i].first;
    }

    sort(c.begin(), c.end());

    vector<int> l(n), r(n);

    for (int i = 1; i < n; i++) {
        l[i] += l[i - 1]; 

        if (c[i - 1].second == 'L') l[i]++;
    }

    for (int i = n - 2; i >= 0; i--) {
        r[i] += r[i + 1];

        if (c[i + 1].second == 'G') r[i]++;
    }

    for (int i = 0; i < n; i++) {
        ans = min(ans, l[i] + r[i]);
    }

    cout << ans << endl;
}