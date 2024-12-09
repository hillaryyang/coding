#include <iostream>
using namespace std;

int vals[100] = {9, 5695, 29, 345, 2841, 69, 2, 41, 306, 1488, 7, 1, 89, 25, 400, 1, 5, 5, 
13, 10, 46, 183, 400, 1, 2, 4, 23, 11, 2997, 2829, 4};

int main() {
    int s1 = 0, s2 = 0;

    for (int i = 0; i < 100; i++) {
        s1 += vals[i];
        if (vals[i] != 0) {
            s2 += (vals[i] * (vals[i] - 1));
        }
    }

    cout << s1 << endl << s2 << endl;

    double ans = s2/(s1*(s1-1));

    printf("%f\n", ans);
}