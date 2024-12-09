#include <iostream>
using namespace std;

int n, avg, ans, sum;
int p[101];

bool in(int i, int j, int avg) {
    for (int l = i; l <= j; l++) {
        if (p[l] == avg) return 1;
    }  
    return 0;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> p[i];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum = 0;
            for (int a = i; a <= j; a++) sum += p[a];
            int c = j-i+1;
            if (sum % c == 0) {

                if (in(i, j, sum/c)) ans++;
            }
        }
    }

    cout << ans << endl;
}