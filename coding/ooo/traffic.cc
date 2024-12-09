#include <iostream>
using namespace std;

string dir[110];
int mn[110], mx[110];

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> mn[i] >> mx[i];
    }

    int x = -999, y = 999;
    for (int i = n - 1; i >= 0; i--) {
        if (dir[i] == "on") {x -= mx[i]; y -= mn[i]; x = max(0, x);}
        else if (dir[i] == "off") {x += mn[i]; y += mx[i];}
        else {x = max(x, mn[i]); y = min(y, mx[i]);}
    }

    cout << x << " " << y << endl;

    x = -9999, y = 9999;
    for (int i = 0; i < n; i++) {
        if (dir[i] == "on") {x += mn[i]; y += mx[i];}
        else if (dir[i] == "off") {x -= mx[i]; y -= mn[i]; x = max(0, x);}
        else {x = max(x, mn[i]); y = min(y, mx[i]);}
    }

    cout << x << " " << y << endl;

}