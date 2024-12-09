/*
ID: hillary3
TASK: crypt1
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[10], ct;

bool digit(char c) {
    bool flag = true;
    int b = c - '0';

    for (int i = 0; i < n; i++) if (a[i] == b) return true;
    return 0;
}

bool ok (int a) {
    bool flag = true;
    string s = to_string(a);

    for (int i = 0; i < s.size(); i++) if (!digit(s[i])) return 0;
    return 1;
}

bool works(int a, int b) {
    int ones = b % 10;
    int tens = (b - ones)/10;

    if (ok(a * ones) && ok(a * tens) 
    && a * ones < 1000 && a * tens < 1000 
    && a * b < 10000 && ok(a * b)) return 1;
    return 0;
}

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 100; i < 1000; i++) {
        if (ok(i)) {
            for (int j = 10; j < 100; j++) {
                if (ok(j)) {
                    if (works(i, j)) ct++;
                }
            }
        }
    }

    cout << ct << endl;
}