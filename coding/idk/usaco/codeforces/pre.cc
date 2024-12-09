#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int ct = 0;
        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n - i - 1]) ct++; 
            else break;
        }

        cout << n - 2 * ct << endl;
    }
}