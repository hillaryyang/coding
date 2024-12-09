#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll n, y, ans = 1e7, bad;
char x;
vector<char> c;
vector<ll> t;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        c.push_back(x); t.push_back(y);
    }

    for (int i = 0; i < n; i++) {
        //t[i] is the h we're testing

        for (int j = 0; j < n; j++) {
            if (j != i) {
                if ((c[j] == 'G' && t[j] > t[i])
                || (c[j] == 'L' && t[j] < t[i])) bad++;
            }
        }

        if (bad < ans) ans = bad; 
        bad = 0;
    }

    cout << ans << endl;
}