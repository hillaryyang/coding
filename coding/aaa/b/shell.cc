#include <iostream>
#include <algorithm>
using namespace std;

int a[100], b[100], g[100], s[3], correct, big;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> g[i];

    for (int i = 0; i < 3; i++) {
        s[i] = 1;
        for (int j = 0; j < n; j++) {
            swap(s[a[j]-1], s[b[j]-1]);
            if (s[g[j]-1] == 1) correct++;
        }

        if (correct > big) big = correct;
        correct = 0;
        for (int i = 0; i < 3; i++) s[i] = 0;
    } cout << big << endl;
}