#include <iostream>
using namespace std;

int ct = 1, n;
bool flag = true;

int main() {
    freopen ("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = n-1; i >= 0; i--) {
        if (a[i] > a[i-1] && flag) ct++;
        
        else if (a[i] < a[i-1]) flag = 0;
    } 
    
    cout << n-ct << endl;
}