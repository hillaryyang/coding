//https://codeforces.com/problemset/problem/1858/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

int main() {
    ll t, n, a, b, c; cin >> t;

    while (t--) {
        cin >> a >> b >> c;

        if (a > b) cout << "First" << endl;
        else if (a < b) cout << "Second" << endl;
        else {
            if (c % 2 == 1) cout << "First" << endl;
            else cout << "Second" << endl;
        }
    }
}