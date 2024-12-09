//https://codeforces.com/contest/1792/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

int t, n, x;
vector<int> a, temp;

bool check(int mid) {
    temp.clear();
    for (int i : a) if (i > mid && i <= n - mid) temp.push_back(i);

    //for (int i : temp) cout << i << " "; cout << endl;
    
    if (temp.size() == 1 || temp.size() == 0) return true;
    for (int i = 0; i < temp.size() - 1; i++) if (temp[i] > temp[i + 1]) return false;

    return true;
}

bool sort() {
    for (int i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) return false;
    return true;
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        a.clear();
        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

        if (sort()) {cout << 0 << endl; continue;}

        int l = 0, r = n/2, ans;
        while (l <= r) {
            int mid = (l + r)/2;
            //cout << l << " " << r << endl;
            if (check(mid)) {r = mid - 1; ans = mid;}
            else l = mid + 1;
        }

        cout << ans << endl;
    }
}