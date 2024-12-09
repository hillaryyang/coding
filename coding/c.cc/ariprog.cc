/*
ID: hillary3
TASK: ariprog
LANG: C++                 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
bool flag[125001];
vector<int> prog, v;
vector<pair<int, int> > res;

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) flag[i*i+j*j] = true;
    }

    for (int i = 0; i < 2*m*m; i++) {
        if (flag[i]) v.push_back(i);
    }

    for (auto a : v) {
        for (int dif = 1; a + dif*(n-1) <= 2*m*m && dif <= m*m; dif++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (!flag[a + dif*i]) {ok = false; break;}
            }
            if (ok) res.push_back(make_pair(dif, a));

            prog.clear();
        }
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++) {
        cout << res[i].second << " " << res[i].first << endl;
    }

    if (res.empty()) cout << "NONE" << endl;
}