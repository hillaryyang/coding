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
    string s; vector<string> a;
    for (int i = 0; i < 8; i++) {cin >> s; a.pb(s);}

    sort(a.begin(), a.end());
    for (auto i : a) cout << i << endl;
}