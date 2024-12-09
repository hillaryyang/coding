#include <iostream>
#include <algorithm>
using namespace std;

int p[100], ct;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) sum += p[k];

            for (int k = i; k <= j; k++) if (sum == p[k] * (j - i + 1)) {ct++; break;}
        }
    }

    cout << ct << endl;
}