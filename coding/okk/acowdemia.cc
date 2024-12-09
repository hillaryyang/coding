#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, h;
vector<int> p;

int hindex() {
    int h = p.size();
    while (h > 0 && p[h - 1] < h) h--;
    return h;
}

int main() {
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p.push_back(x);
    }

    sort(p.begin(), p.end(), greater<int>());

    int h = hindex();
    if (h != n) {
        for (int i = h; i >= max(0, h - l + 1); i--) {
            p[i]++;
        }
    }

    sort(p.begin(), p.end(), greater<int>());

    cout << hindex() << endl;
}