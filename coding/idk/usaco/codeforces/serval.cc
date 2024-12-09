//https://codeforces.com/contest/1789/problem/A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    
    return gcd(b, a % b);
}

int main() {
    int t, n, x; cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

        bool ok = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                //a[i] and a[j];
                if (gcd(a[i], a[j]) <= 2) {ok = true; break;}
            }
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}