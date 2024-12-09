//https://codeforces.com/problemset/problem/1841/A
#include <iostream>
using namespace std;

int t, n;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        if (n <= 4) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
}