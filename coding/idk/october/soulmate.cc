#include <iostream>
#include <vector>
#include <tuple>
#include <queue> 
#include <algorithm>
#define pb push_back
#define mt make_tuple
#define ll long long
#define f first
#define s second
using namespace std;

ll solve(ll a, ll b) {
   // cout << a << " " << b << endl; return 0;
    if (a == b) return 0;

    ll ct = 0;

    //we reduce a to be less than b
    if (a > b) {
        if (a & 1) {a++; ct++;}
        return solve(a/2, b) + 1 + ct;
    }

    //bring b down
    else if (a <= b/2) {
        if (b & 1) {b--; ct++;}
        return solve(a, b/2) + 1 + ct;
    }

    //a is between b/2 and b
    else {
        ll add = b - a;
        if (a & 1) {a++; ct++;}
        if (b & 1) {b--; ct++;}
        return min(add, solve(a/2, b/2) + 2 + ct);
    }
}

int main() {
    ll n, x, y; cin >> n;

    while (n--) {
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
}