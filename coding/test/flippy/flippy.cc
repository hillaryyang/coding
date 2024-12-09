#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }

    int ct = 0;

    for (int i = 0; i < n; i++) {
        // cout << i + 1 << " " << n - i << endl;
        if (a[i] != i + 1 && a[i] != n - i) {cout << -1 << endl; return 0;}
        else if (a[i] != i + 1) ct++;
    }

    cout << ct/2 << endl;
}