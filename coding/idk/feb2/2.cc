#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
const int N = 1e5 + 10;
using namespace std;

bool vis[N];

int main() {
    int n, s; map<int, int> tar, jump;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int q, v; cin >> q >> v;
        if (q == 0) jump[i + 1] = v;
        else tar[i + 1] = v;
    }

    int hit = 0, pow = 1, dir = 1, mx = tar.size(), ct = 0;
    while (s <= n && s >= 1 && hit < mx && ct < 1e6) {
        //if (vis[s]) break; vis[s] = true;

        if (tar.find(s) != tar.end() && tar[s] <= pow) {
            hit++;
            tar.erase(s);
        }
        else if (jump.find(s) != jump.end()) {
            dir = -1 * dir;
            pow += jump[s];
        }

        if (dir == 1) s += pow;
        else s -= pow;

        ct++;
    }

    cout << hit << endl;
}