#include <iostream>
using namespace std;

int n, order[100], pass[100], ans;

int nex(int a) {
    int ldist = 1000, rdist = 1000;
    int l, r;

    for (int i = 0; i < n; i++) {
        if (order[i] < order[a] && order[a] - order[i] < ldist) {
            l = i;
            ldist = order[a] - order[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (order[i] > order[a] && order[i] - order[a] < rdist) {
            r = i;
            rdist = order[i] - order[a];
        }
    }

    if (ldist == rdist) return l;
    if (ldist < rdist) return l;
    else return r;
}

int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> order[i];
    for (int i = 0; i < n; i++) pass[nex(i)]++;

    for (int i = 0; i < n; i++) {
        if (pass[i] == 0) ans++;
        else if (nex(nex(i)) == i && pass[i] == 1 && pass[nex(i)] == 1 && i < nex(i)) ans++;
    }

    cout << ans << endl;
}