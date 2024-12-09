//http://www.usaco.org/index.php?page=viewproblem2&cpid=893
#include <iostream>
#include <vector>
using namespace std;

int ct, n, k, mx;
string a, b;

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    
    cin >> n;
    vector<vector<string> > c(n);

    for (int i = 0; i < n; i++) {
        cin >> a >> k;

        while (k--) {cin >> a; c[i].push_back(a);}
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ct = 0;
            for (int k = 0; k < c[i].size(); k++) {
                for (int l = 0; l < c[j].size(); l++) {
                    if (c[i][k] == c[j][l]) ct++;
                }
            }

            mx = max(mx, ct);
        }
    }

    cout << mx + 1 << endl;
}