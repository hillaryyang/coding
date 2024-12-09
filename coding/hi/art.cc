#include <iostream>
#include <string>
using namespace std;

int n, ans, canvas[11][11];
string s;
bool valid;

bool there(int a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (canvas[i][j] == a) return 1;
        }
    }
    
    return 0;
}

bool over(int a, int b) {
    int l = n, r = 0, u = n, d = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (canvas[i][j] == b) {
                l = min(l, j);
                r = max(r, j);
                u = min(u, i);
                d = max(d, i);
            }
        }
    }

    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            if (canvas[i][j] == a) return true;
        }
    }

    return false;
}

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) canvas[i][j] = s[j] - '0';
    }

    for (int i = 1; i <= 9; i++) {
        if (there(i)) {
            valid = true;
            for (int j = 1; j <= 9; j++) 
                if (there(j) && i != j && over(i, j)) valid = false;
            if (valid) ans++;
        }
    }

   cout << ans << endl;
}