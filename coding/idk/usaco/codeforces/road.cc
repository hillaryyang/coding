#include <iostream>
using namespace std;

const int N = 100010;

int n, m, p[N], s[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {p[i] = i; s[i] = 1;}

    int mx = 1;

    while (m--) {
        int a, b; cin >> a >> b;

        if (find(b) != find(a)) {s[find(b)] += s[find(a)]; p[find(a)] = find(b); n--;}
        mx = max(mx, s[find(b)]);
        //cout << find(a) <<" " << s[find(a)] << " " << find(b) << " " << s[find(b)] << endl;

        //for (int i = 1; i <= n; i++) cout << s[i] << " "; cout << endl;
        //for (int i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;
        //cout << endl;

        cout << n << " " << mx << endl; 
    }
}