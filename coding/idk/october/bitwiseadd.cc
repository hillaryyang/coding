#include <iostream>
using namespace std;

int add(int a, int b) {
    int c = a & b;
    while (c) {
        c = a & b;
        a ^= b;
        b = c << 1;
    }

    return a;
}

int main() {
    int a, b; cin >> a >> b;
    cout << add(a, b) << endl;
}