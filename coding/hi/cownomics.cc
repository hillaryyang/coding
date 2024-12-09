#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int m, n, ct;
string spotty[100], plain[100];

bool test (int j) {
    bool found[2][4] = {0};
    for (int i=0; i<n; i++) {
        if (spotty[i][j] == 'A') found[0][0] = true;
        if (spotty[i][j] == 'C') found[0][1] = true;
        if (spotty[i][j] == 'G') found[0][2] = true;
        if (spotty[i][j] == 'T') found[0][3] = true;
    }

    for (int i=0; i<n; i++) {
        if (plain[i][j] == 'A') found[1][0] = true;
        if (plain[i][j] == 'C') found[1][1] = true;
        if (plain[i][j] == 'G') found[1][2] = true;
        if (plain[i][j] == 'T') found[1][3] = true;
    }

    for (int i = 0; i < 4; i++) {
        if (found[0][i] && found[1][i]) return false;
    } return true;
}

using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> spotty[i];
    for (int i = 0; i < n; i++) cin >> plain[i];

    for (int j = 0; j < m; j++) 
        if (test(j)) ct++;
    cout << ct << endl;
}