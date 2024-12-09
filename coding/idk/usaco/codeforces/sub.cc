//https://codeforces.com/contest/1794/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int t, n, x, ans;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> s, a;

        for (int i = 0; i < n; i++) {cin >> x; s.push_back(x);}

        //for (auto c : s) cout << c << " "; cout << endl;

        for (int i = 0; i < n; i++) {
            int l = 0, r = i, ans = 0;

            while (l <= r) {
                int mid = (l + r)/2;
                if (s[mid] >= i - mid + 1) {r = mid - 1; ans = mid;}
                else l = mid + 1;
                //cout << i << " " << s[mid] << " " << i - mid + 1 << endl;
            }

            a.push_back(i + 1 - ans);
        }

        for (int i : a) cout << i << " ";
        cout << endl;
    }
}  

