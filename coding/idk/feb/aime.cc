#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int sum(int n) {
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n/10;
    }
    return sum;
}

int main() {
    for (int i = 1; i < 1000; i++) {
        if (sum(i) == 20 && sum(i) == sum(i + 864)) {
            cout << i << endl; return 0;
        }
    }
}