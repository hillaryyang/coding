#include <iostream>
using namespace std;

int a1, a2, b1, b2, n, k, o[100];

int nex(int x) {
    if (a1 <= x && x <= a2) x = a1 + a2 - x;
    if (b1 <= x && x <= b2) x = b1 + b2 - x;

    return x;
}

int main() {
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;

    for (int i = 1; i <= n; i++) {
        int repeat = 1, cur = nex(i);

        while (cur != i) {
            repeat++;
            cur = nex(cur);
        }

        int r = k%repeat;

        for (int j = 0; j < r; ++j) cur = nex(cur);
        o[cur] = i;
    }

    for (int i = 1; i <= n; i++) cout << o[i] << endl;
}