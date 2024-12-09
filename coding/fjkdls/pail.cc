#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m, mx = 0;
    cin >> x >> y >> m;

    for (int i = 0; i <= m/x; i++) {
        int other = (m - i * x)/y;
        if (other * y + x * i > mx) mx = other * y + x * i;
    }

    cout << mx << endl;
}