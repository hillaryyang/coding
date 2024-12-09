#include <iostream>
#define ll long long
using namespace std;

ll n, k, d[100000], cost;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> d[i];

        if (i == 0) cost += k + 1;

        else cost += min(k+1, d[i] - d[i-1]);
    }

    cout << cost << endl;
}