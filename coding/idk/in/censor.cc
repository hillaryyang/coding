#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

string s, t, cur;

int main() {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    
    cin >> s >> t;

    for (int i = 0; i < s.length(); i++) {
        cur += s[i];
        
        bool flag = true;
        int x = cur.length(), y = t.length();
        for (int j = x - y; j < x; j++) if (cur[j] != t[j + y - x]) flag = false;
        
        if (flag) {
            cur.erase(x - y, x);
        }
    }

    cout << cur << endl;
}