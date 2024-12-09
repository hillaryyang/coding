#include <iostream>
#define ll long long
using namespace std;

ll n, b[10000], mn = 1e9;
char a[10000];

int main() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    for (int i = 0; i < n; i++) {
        //bessie is at b[i]
        ll cur = 0;
        for (ll j = 0; j < n; j++) {
            if (a[j] == 'G' && b[i] < b[j]) cur++;
            else if (a[j] == 'L' && b[i] > b[j]) cur++;
        }

        if (cur < mn) mn = cur;
    }

    cout << mn << endl;
}