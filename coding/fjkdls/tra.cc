#include <iostream>
#include <algorithm>
using namespace std;

int n, x[1000], y[1000], mx;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    
    cin >> n;

    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j && i != k && j != k) {
                    if (x[j] - x[i] == 0 && y[k] - y[i] == 0) {
                        int area = abs((y[j] - y[i]) * (x[k] - x[i]));
                        mx = max(mx, area);
                    }
                }
            }
        }
    }

    cout << mx << endl;
}