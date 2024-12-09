//https://codeforces.com/contest/1840/problem/D
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<int> a;

bool check (int n) {
    int used = 1, l = 0;
    for (int i = 1; i < a.size(); i++) {
        int val = (a[i] + a[l])/2;
        if (used > 3) return false;
        else if (a[i] - val > n || val - a[l] > n) {
            used++; l = i;
            if (used > 3) return false;
        }
       // cout << l << " " << i << " " << val << " " << used << endl;
    }

    return true;
}

int main() {
    int t, n, x; cin >> t;

    while (t--) {
        cin >> n;

        int r = 0;
        for (int i = 0; i < n; i++) {
            cin >> x; a.push_back(x);
            r = max(r, x);
        }

        sort(a.begin(), a.end());

        int l = 0, ans;
        while (l <= r) {
            int mid = (l + r)/2;
            if (check(mid)) {r = mid - 1; ans = mid;}
            else l = mid + 1;
        }
        
        //cout << check(1) << endl;

        cout << ans << endl;
        a.clear();
    }
}