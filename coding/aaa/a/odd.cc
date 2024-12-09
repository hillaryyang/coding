#include <iostream>
using namespace std;

int o, e, n, a, t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a%2==0) e++; else o++;
    }

    if (e == o || e == o+1) {cout << n << endl; return 0;}

    while (e < o) {e++; o-=2; t++;}

    if (e == o || e == o+1) {cout << n-t << endl; return 0;}
    if (e > o+1) {cout << 2*o+1 << endl; return 0;}

}