#include <iostream>
using namespace std;

int k, n, ct, arr[11][21];

bool consistent(int a, int b) {
    int loc1, loc2;
    bool ok = true;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == a) loc1 = j;
            else if (arr[i][j] == b) loc2 = j;
        }

        if (loc1 < loc2) ok = true;
        else {ok = false; break;}
    }

    if (ok) return true;
    return false;
}

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && consistent(i, j)) ct++;
        }
    }

    cout << ct << endl;
}