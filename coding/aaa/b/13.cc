/*
ID: hillary3
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <map>

using namespace std;

int n, ans[7];
int numdays[12] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2};

bool leapyear(int i) {
    if (i % 100 != 0 && i % 4 == 0) return true;
    else if (i % 100 == 0 && i % 400 == 0) return true;
    return false;
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    
    cin >> n;

    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (!leapyear(1900+i)) {
            cur += 12; cur = cur % 7;
            ans[cur]++;

            for (int j = 0; j < 11; j++) {
                cur += numdays[j]; cur %= 7;
                ans[cur]++;
            }
        }

        else if (leapyear(1900+i)) {
            int leap[12] = {3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2};
            cur += 12; cur = cur % 7;
            ans[cur]++;

            for (int j = 0; j < 11; j++) {
                cur += leap[j]; cur %= 7;
                ans[cur]++;
            }
        }

        cur = (cur + 19) % 7;
    }

    cout << ans[5] << " " << ans[6] << " " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4];
    cout << endl;
}