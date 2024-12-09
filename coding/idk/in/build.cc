#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, ct;
vector<int> h;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {int x; cin >> x; h.push_back(x);}

    for (int i = 0; i < n - 1; i++) {
        h[i] = max(h[i] - h[i + 1], 0);
    }

    for (auto c : h) ct += c;

    cout << ct << endl;
}