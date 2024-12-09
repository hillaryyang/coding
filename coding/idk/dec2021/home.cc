//http://www.usaco.org/index.php?page=viewproblem2&cpid=1157
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
#define f first
using namespace std;

int solve1(char a[51][51], int n) {
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) if (a[0][i] == 'H') x = 1;
    for (int i = 0; i < n; i++) if (a[i][n - 1] == 'H') x = 1;
    
    for (int i = 0; i < n; i++) if (a[i][0] == 'H') y = 1;
    for (int i = 0; i < n; i++) if (a[n - 1][i] == 'H') y = 1;

    return 2 - x - y;
}

int solve2(char a[51][51], int n) {
    int ans = 0;
    //pairs that sum to n
    for (int i = 1; i < n - 1; i++) {
        //i and n - i
        bool ok = true;
        if (a[0][i] == 'H') break;

        for (int j = 0; j < n; j++) if (a[j][i] == 'H') ok = false;
        if (!ok) continue;
        ok = true;
        for (int j = i; j < n; j++) if (a[n - 1][j] == 'H') ok = false;
        if (!ok) continue;
        ans++;
    }

    for (int i = 1; i < n - 1; i++) {
        //i and n - i
        bool ok = true;
        if (a[i][0] == 'H') break;

        for (int j = 0; j < n; j++) if (a[i][j] == 'H') ok = false;
        if (!ok) continue;
        ok = true;
        for (int j = i; j < n; j++) if (a[j][n - 1] == 'H') ok = false;
        if (!ok) continue;
        ans++;
    }

    return ans;
}

int solve3(char a[51][51], int n) {
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            bool ok = true;
            for (int k = 1; k <= i; k++) if (a[k][0] == 'H') ok = false;
            if (!ok) continue;
            ok = true;
            for (int k = 0; k <= j; k++) if (a[i][k] == 'H') ok = false;
            if (!ok) continue;
            ok = true;
            for (int k = i; k < n; k++) if (a[k][j] == 'H') ok = false;
            if (!ok) continue;
            ok = true;
            for (int k = j; k < n; k++) if (a[n - 1][k] == 'H') ok = false;
            if (!ok) continue;

            ans++;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            bool ok = true;
            for (int k = 1; k <= i; k++) if (a[0][k] == 'H') ok = false;
            if (!ok) continue;
            ok = true;
            for (int k = 0; k <= j; k++) if (a[k][i] == 'H') ok = false;
            if (!ok) continue;
            ok = true;
            for (int k = i; k < n; k++) if (a[j][k] == 'H') ok = false;
            if (!ok) continue;
            ok = true;
            for (int k = j; k < n; k++) if (a[k][n - 1] == 'H') ok = false;
            if (!ok) continue;

            ans++;
        }
    }

    return ans;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n, k; char a[51][51];
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) a[i][j] = s[j];
        }

        if (k == 1) {
            cout << solve1(a, n) << endl;
        }

        else if (k == 2) {
            cout << solve1(a, n) + solve2(a, n) << endl;
        }

        else {
            cout << solve1(a, n) + solve2(a, n) + solve3(a, n) << endl;
        }
    }
}