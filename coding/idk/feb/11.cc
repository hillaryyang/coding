#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e7;

long long n, t, day[N], bale[N];
bool ok[N];
int ct;

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> day[i] >> bale[i];

    for (int i = 0; i < n; i++) {
        if (day[i] > t) continue;
        else {
            for (int j = day[i]; j <= min(day[i] + bale[i] - 1, t); j++) ok[j] = true;
        }
    }

    for (int i = 1; i <= t; i++) if (ok[i]) ct++;
    
    cout << ct << endl;
}