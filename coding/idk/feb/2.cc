#include <iostream>
#include <vector>
using namespace std; 

int t, n, k;
string s;
char can[20][20], stamp[20][20];

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) can[i][j] = s[j];
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) stamp[i][j] = s[j];
        }

        if (k == 1 && stamp[0][0] == '*') cout << "YES" << endl;
        else if (k == 1 && stamp[0][0] == '.') cout << "NO" << endl; 

        else if (k == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (stamp[i][j] != can[i][j]) {cout << "NO" << endl; return 0;}
                }
            } 
            cout << "YES" << endl; return 0;
        }

        else {
            
        }
    }
}
