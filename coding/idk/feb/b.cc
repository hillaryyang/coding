#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cube (int a, int b) {
    for (int i = 1; i <= 30; i++) {
        if (a < i * i * i && i * i * i <= b) return true;
    } return false;
}

int q (int m) {
    bool flag;
    for (int i = 1; i < 33; i++) { //goes thru Q(m)s
        for (int n = i; n < 33; n++) {
            if (cube(n, m*n)) flag = true; 
            else {flag = false; break;}
        }
        if (flag) return i;
    }
    
    return 0;
}

int main() {
    int sum = 0; 

    for (int i = 2; i <= 2017; i++) sum += q(i);

    cout << sum % 1000 << endl;
}