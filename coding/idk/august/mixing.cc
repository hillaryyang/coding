//http://www.usaco.org/index.php?page=viewproblem2&cpid=855
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define f first 
#define s second 
#define mp make_pair
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    
    ll c[4], amt[4];

    for (int i = 0; i < 3; i++) cin >> c[i] >> amt[i];
    
    int cur = 0, nex;
    for (int i = 1; i <= 100; i++) {
        nex = (cur + 1) % 3;

        if (amt[cur] + amt[nex] <= c[nex]) {amt[nex] = amt[cur] + amt[nex]; amt[cur] = 0;}
        else {amt[cur] = amt[cur] + amt[nex] - c[nex]; amt[nex] = c[nex];}

        cur = nex;
    }

    for (int i = 0; i < 3; i++) cout << amt[i] << endl;
}