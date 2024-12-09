#include <iostream>
using namespace std;

int n, x, y, b, big, ans[1000];

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    
    cin >> n;
    int x, y, b;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> b;
        for (int i = x; i <= y; i++) ans[i] += b;
    }

    for (int i = 0; i < 1000; i++) {
        if (ans[i] > big) big = ans[i];
    } cout << big << endl;
}