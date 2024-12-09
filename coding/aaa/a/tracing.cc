#include <iostream>
#include <algorithm>
using namespace std;

int n, t, stime, x[251], y[251], num[101];
bool endstate[101], iok[101] = {false}, kok[251] = {false};
string s;

bool ok(int i, int k) {
    bool infected[101] = {false};
    infected[i] = true;

    for (int i = 0; i <= 250; i++) {
        int cow1 = x[i], cow2 = y[i];
        if (cow1 > 0) {
            if (infected[cow1]) num[cow1]++;
            if (infected[cow2]) num[cow2]++;
            if (num[cow1] <= k && infected[cow1]) infected[cow2] = true;
            if (num[cow2] <= k && infected[cow2]) infected[cow1] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (infected[i] != endstate[i]) return false;
    } return true;
}

int main() {
    cin >> n >> t >> s;
    for (int i = 1; i <= n; i++) endstate[i] = s[i] == '1';
    
    for (int i = 0; i < t; i++) cin >> stime >> x[stime] >> y[stime];

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= 251; k++) {
            if (ok(i, k)) {iok[i] = true; kok[k] = true;}
        }
    }

    int upper = 0, lower = 251, ct = 0;
    for (int i = 0; i <= 251; i++) if (kok[i]) upper = i;
    for (int i = 251; i >= 0; i--) if (kok[i]) lower = i;
    for (int i = 1; i <= n; i++) if (iok[i]) ct++;

    cout << ct << " " << lower << " ";
    if (upper == 251) cout << "Infinity" << endl;
    else cout << upper << endl;
}