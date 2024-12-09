#include <iostream>
#include <vector>
using namespace std;

string dir[110];
vector<pair<int, int> > rd;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> dir[i] >> a >> b;
        rd.push_back(make_pair(a, b));
    }

    //back to front
    int x = -99999, y = 99999;
    for (int i = n - 1; i >= 0; i--) {
        if (dir[i] == "off") {x += rd[i].first; y += rd[i].second;}
        else if (dir[i] == "on") {x -= rd[i].second; y -= rd[i].first; x = max(x, 0);}
        else {
            x = max(x, rd[i].first); 
            y = min(y, rd[i].second);
        }
    }

    cout << x << " " << y << endl;

    //front to back
    x = -99999, y = 99999;

    for (int i = 0; i < n; i++) {
        if (dir[i] == "on") {x += rd[i].first; y += rd[i].second;}
        else if (dir[i] == "off") {x -= rd[i].second; y -= rd[i].first; x = max(0, x);}
        else {
            x = max(x, rd[i].first); 
            y = min(y, rd[i].second);
        }
    }

    cout << x << " " << y << endl;
}