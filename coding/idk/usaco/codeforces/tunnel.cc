//https://codeforces.com/contest/1237/problem/B
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

int n, x, ct, loc1[1000000], loc2[1000000], loc[1000000], mn[1000000];
vector<int> in, out;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; in.push_back(x);}
    for (int i = 0; i < n; i++) { cin >> x; out.push_back(x);}

    reverse(in.begin(), in.end());
    reverse (out.begin(), out.end());

    //bro... help
    for (int i = 0; i < n; i++) loc1[in[i]] = i;
    for (int i = 0; i < n; i++) loc2[out[i]] = i;
    for (int i = 1; i <= n; i++) loc[loc1[i]] = loc2[i];

    //setting minimums
    mn[n - 1] = loc[n - 1];
    for (int i = n - 2; i >= 0; i--) mn[i] = min(mn[i + 1], loc[i]);

    //finding violators
    for (int i = 0; i < n - 1; i++) if (loc[i] > mn[i + 1]) ct++;

    cout << ct << endl;
}