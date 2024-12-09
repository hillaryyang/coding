#include <iostream>
using namespace std;

int cow[10][10], ct, ans;

void flip(int a, int b) {
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (cow[i][j] == 1) cow[i][j] = 0;
            else cow[i][j] = 1;
        }
    }
}

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++) cow[i][j] = (int) (s[j] - '0');
    }

    int dist = 2*n - 2;

    while (dist >= 0) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i + j == dist && cow[i][j] == 1) {flip(i, j); ans++;}
            }
        }
        dist--;
    }

    cout << ans << endl;
}