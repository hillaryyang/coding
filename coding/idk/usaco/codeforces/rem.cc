//https://codeforces.com/contest/1800/problem/D
#include <iostream>
using namespace std;

int main() {
    int t, n; string s;  
    cin >> t;
    
    while (t--) {
        cin >> n >> s; int ans = n - 1;
        for (int i = 0; i < n - 2; i++) if (s[i] == s[i + 2]) ans--;
        cout << ans << endl;
    }
}