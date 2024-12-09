#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define ll long long
#define pb push_back
#define f first
#define pii pair<int, int>
#define mp make_pair
const int N = 105;
using namespace std;

int main() {
    int n, ans = 0, ni = 4e5; string s;

    cin >> n >> s;

    vector<int> cts; int ct = 0;
    for (char i : s) {
        if (i == '1') ct++;
        else if (ct != 0) {cts.pb(ct); ct = 0;}
    } if (ct != 0) cts.pb(ct);

    //for (int i : cts) cout << i << " "; cout << endl;

    vector<int> nights; 

    for (int i = 0; i < cts.size(); i++) {
        if (i == 0 && s[0] == '1') nights.pb(cts[i] - 1);
        else if (i == cts.size() - 1 && s.back() == '1') nights.pb(cts[i] - 1);
        else nights.pb((cts[i] + 1)/2 - 1);
    }
    for (int i : nights) cout << i << " "; cout << endl;
    for (int i : nights) ni = min(ni, i);

    cout << ni << endl;
    
    for (int i = 0; i < cts.size(); i++) {
        //if (i == 0 && s[0] == '1') ans += cts[0] - ni;
        //else if (i == cts.size() - 1 && s.back() == '1') ans += cts[i] - ni;
        ans += cts[i] - 2 * ni;
    }

    cout << ans << endl;
}

