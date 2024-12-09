/*
ID: hillary3
TASK: ride
LANG: C++                 
*/

#include <iostream>
using namespace std;

int main() {
    freopen ("ride.in", "r", stdin);
    freopen ("ride.out", "w", stdout);

    string a, b; 
    int prod1 = 1, prod2 = 1;

    cin >> a >> b;

    for (int i = 0; i < a.size(); i++) prod1 *= a[i] - 'A' + 1;
    for (int i = 0; i < b.size(); i++) prod2 *= b[i] - 'A' + 1;

    if (prod1 % 47 == prod2 % 47) cout << "GO" << endl;
    else cout << "STAY" << endl;

    return 0;
}