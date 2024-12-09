#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll n, t, over, ct, a, b;
vector <ll> s, e;

int main() {
    cin >> n >> t;
    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        s.push_back(a); e.push_back(a+b-1);
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (e[i] >= s[j] && s[j] <= t) {
                if (s[j] <= t && e[i] >= t) {over += (t-s[j]+1);}
                else if (e[i] <= t) {over += e[j] - s[j] + 1;}
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        if (s[i] < t && e[i] <= t) ct += e[i] - s[i] + 1;
        else if (s[i] < t && e[i] > t) ct += t - s[i] + 1;
        else if (s[i] == t) ct += 1;
    } 

    cout << ct - over << endl;
}