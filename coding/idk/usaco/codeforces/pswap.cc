//https://codeforces.com/contest/1828/problem/B
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t, n, p[100000], dist[100000];

int gcd (int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> p[i];
            dist[i] = (int) abs(p[i] - i - 1);
        }
        
        int ans = dist[0];
        for (int i = 1; i < n; i++) ans = gcd(ans, dist[i]);

        cout << ans << endl;

        for (int i = 0; i < n; i++) {
            p[i] = 0; dist[i] = 0;
        }
    }
}