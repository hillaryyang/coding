/*
ID: hillary3
TASK: barn1
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, s, c, a, val[200];
vector <int> dif;

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    cin >> m >> s >> c;
    for (int i = 0; i < c; i++) cin >> val[i];

    sort(val, val+c);
    int tot = abs(val[c-1] - val[0] + 1);

    for (int i = 0; i < c - 1; i++) dif.push_back(val[i+1] - val[i]);
    sort(dif.begin(), dif.end(), greater<int>());

    //for (auto c : dif) cout << c << " ";

    int b = min(m-1, c-1);
    for (int i = 0; i < b; i++) tot -= dif[i] - 1;
    cout << tot << endl;
}