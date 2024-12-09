//https://codeforces.com/contest/1808/problem/B
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t, n; string s;
    
    cin >> t;

    while (t--) {
        cin >> n >> s;

        char mn = 'z';

        for (char c : s) if (c < mn) mn = c;
        for (int i = n - 1; i >= 0; i--) if (s[i] == mn) {s.erase(s.begin() + i); break;}

        s.insert(s.begin(), mn);

        cout << s << endl;
    }
}