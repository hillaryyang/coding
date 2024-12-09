#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, loc, mn, mx; 
string s; vector<int> ans;

int main() {
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        if (s[i] != 'F') {
            for (int j = i + 1; j < n; j++) if (s[j] != 'F') {loc = j; break;}

            int num = loc - i - 1;

            if (s[i] == s[loc]) {
                if (num % 2 == 0) {mn++; mx += num + 1;}
                else mx += num + 1;
            }

            else {
                if (num % 2 == 1) {mn++; mx += num;}
                else mx += num;
            }
        }
    }

    int st = 0, en = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') st++;
        else break;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'F') en++;
        else break;
    }

    if (st == n) {
        for (int i = 0; i < n; i++) ans.push_back(i);

        cout << ans.size() << endl;
        for (int i : ans) cout << i << endl;
    }

    else if (st == 0 && en == 0) {
        for (int i = mn; i <= mx; i += 2) ans.push_back(i);

        cout << ans.size() << endl;
        for (int i : ans) cout << i << endl;
    }

    else {
        mx += (st + en);
        for (int i = mn; i <= mx; i++) ans.push_back(i);

        cout << ans.size() << endl;
        for (int i : ans) cout << i << endl;
    }
}