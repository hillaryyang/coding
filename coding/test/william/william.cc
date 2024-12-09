#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

const ll N = 1000000007;

ll fib(ll n){
    if (n <= 1) return n;
    vector<ll> a(n + 1);
    a[0] = 0, a[1] = 1;

    for (int i = 2; i <= n; i++) a[i] = (a[i - 1] + a[i - 2]) % N;
    return a[n];
}

int main() {
    ll n; cin >> n;
    ll f = fib(n + 1) % N;
    ll x = f * f;
    // cout << fib(n + 1) % N << endl;

    cout << x % N << endl;
}