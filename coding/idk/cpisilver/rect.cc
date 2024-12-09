//https://codeforces.com/contest/1365/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second
const ll N = 2503;
using namespace std;

ll n, x, y, ans;
vector<pair<ll, ll> > cow;
int a[N][N], pre[N][N];

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.s < b.s;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> x >> y; cow.pb(mp(x, y));}

    //compress
    map<ll, ll> ry;
    sort(cow.begin(), cow.end(), cmp);
    for (int i = 0; i < n; i++) ry[cow[i].s] = i;

    sort(cow.begin(), cow.end());
    for (int i = 0; i < n; i++) {cow[i].f = i + 1; cow[i].s = ry[cow[i].s] + 1;}

    //prefix sums
    for (auto i : cow) a[i.f][i.s] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
    }

    //loop through cows /
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll l = min(cow[i].f, cow[j].f), r = max(cow[i].f, cow[j].f);
            ll u = max(cow[i].s, cow[j].s), d = min(cow[i].s, cow[j].s);

            //cows above
            //cout << l << " " << r << " " << u << " " << d << endl;
            ll A = r, B = n, a = l, b = u + 1, lo;
            //cout << A << " " << B << " " << a << " " << b << endl;
            ll hi = pre[A][B] - pre[a - 1][B] - pre[A][b - 1] + pre[a - 1][b - 1];

            A = r, B = d-1, a = l, b = 1;
            //cout << A << " " << B << " " << a << " " << b << endl;
            lo = pre[A][B] - pre[a - 1][B] - pre[A][b - 1] + pre[a - 1][b - 1];
            //cout << hi << " " << lo << endl; cout << endl;

            ans += (hi + 1) * (lo + 1);
        }
    }

    cout << ans + n + 1 << endl;
}