//
#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

int n, k, m, x, y, loc, ans;
vector<int> a;
vector<vector<int> > re(110);

bool cook (int ing) {
    if (a[ing] != 0) {a[ing]--; return 1;}

    if (re[ing].empty()) return 0;
    
    bool ok = true;
    for (int i : re[ing]) {
        if (a[i] != 0) a[i]--;
        else if (!cook(i)) return 0;
    }

    return 1;
}

int main() {
    cin >> n;
    a.push_back(0); for (int i = 0; i < n; i++) {cin >> x; a.push_back(x);}

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> m;
        while (m--) {cin >> y; re[x].push_back(y);}
    }

    while (cook(n)) ans++;
    
    cout << ans << endl;
}