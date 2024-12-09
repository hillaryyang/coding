#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int A, b, c, a[7];

int main() {
    for (int i = 0; i < 7; i++) cin >> a[i];

    sort(a, a+7);

    A = a[0], b = a[1];
    c = a[6] - A - b;

    cout << A << " "<< b << " " << c << endl;
}