#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

string a;

int main() {
    int t; cin >> t;

    string dig = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
   
    while (t--) {
        cin >> a;

        int ct = 0;

        for (int i = 0; i < a.size(); i++) {
            if (dig[i] == a[i]) ct++;
            else break;
        }

        cout << ct << endl;
    }
    return 0;
}
