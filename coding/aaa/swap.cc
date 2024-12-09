//3:07
#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

int n, k, a1, a2, b1, b2, ct = -1, ans[110], temp[110]; 

void swap() {
    for (int i = 1; i <= n; i++) temp[i] = ans[i];
    //first a swap
    for (int i = a1; i <= a2; i++) ans[i] = temp[a1 + a2 - i];
    //reset temp
    for (int i = 1; i <= n; i++) temp[i] = ans[i];
    //first b swap
    for (int i = b1; i <= b2; i++) ans[i] = temp[b1 + b2 - i];
}

bool check() {
    for (int i = 1; i <= n; i++) if (ans[i] != i) return false;
    return true;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    for (int i = 1; i <= n; i++) ans[i] = i;

    for (int i = 1; i <= k; i++) {
        swap(); if (check()) {ct = i; break;}
    } 

    int t = k % ct;
    if (ct != -1) for (int i = 0; i < t; i++) swap();

    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}