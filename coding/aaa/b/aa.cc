#include <iostream>
using namespace std;

int ct, a[5];

int main() {
    for (int i = 7; i < 1000; i++) {
        for (int j = 2; j <= 6; j++) a[j-2] = i % j;

        sort (a, a + 5); 

        bool flag = true;

        for (int j = 0; j < 5; j++) {
            if (a[j] == a[j+1]) {flag = false; break;}
            else if (a[j] != a[j+1]) flag = true;
        }

        if (flag) ct++;

        for (int i = 0; i < 5; i++) a[i] = 0;
    }

    cout << ct << endl;
}