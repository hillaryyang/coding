//https://codeforces.com/contest/1857/problem/A
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, x; cin >> t;

    while (t--) {
        int s = 0; cin >> n; 

        while (n--) {cin >> x; s += x;}

        if (s % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }       
}