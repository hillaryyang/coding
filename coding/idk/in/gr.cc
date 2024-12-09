#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, b, x, y;

int main() {
    cin >> n >> b >> x >> y;

    int bluecost = (4*n-4) * y;
    int whitecost = (n-2) * (n-2) * x;

    if (bluecost + whitecost < b) cout << "Walter will like this lab" << endl;
    else cout << "Sorry Mr. Fring, no can do" << endl;

    return 0;
}
