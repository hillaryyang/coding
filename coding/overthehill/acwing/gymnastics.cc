#include <iostream>
#include <vector>
using namespace std;

int k, n, ct, cow1, cow2, pos1, pos2, b; 

int main() {

    freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
    
    cin >> k >> n;
    int a[k][n];

    for (int i = 0; i < k; i++) {for (int j = 0; j < n; j++) cin >> a[i][j];}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cow1 = i+1; cow2 = j+1;
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < n; j++) {
                        if (a[i][j] == cow1) pos1 = j;
                        else if (a[i][j] == cow2) pos2 = j;
                    }
                    if (pos1 < pos2) b++;
                } if (b == k) ct++;
            }
            b = 0;
        }
    }
    cout << ct << endl;
}