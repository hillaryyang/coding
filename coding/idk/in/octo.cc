#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, b[30][30];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) b[i][j] = s[j];
    }


}