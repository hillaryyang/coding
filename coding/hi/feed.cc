#include <iostream>
using namespace std;

int t, n, k;
string cows, ans;

int main() {
    cin >> t;
    while (t--) {

        cin >> n >> k >> cows;

        int ct = 0;
        
        char ans[n]; bool used[n], u[n];

        for (int i = 0; i < n; i++) { ans[i] = '\0'; used[i] = false;}

        if (k == 0) { cout << n << endl << cows << endl; continue; }

        else {
            //deals with Guernsey's first
            for (int i = 0; i < n; i++) {
                if (cows[i] == 'G' && !used[i]) { 
                    if (i+k < n) {
                        ans[i + k] = 'G';
                        for (int j = i; j <= i + 2*k; j++) 
                            if (cows[j] == 'G') {used[j] = true;}
                    }

                    else if (i+k >= n) {ans[n-1] = 'G'; break; }
                }
            }
            
            for (int i = 0; i < n; i++) {
                if (cows[i] == 'H' && !used[i]) {
                    if (i+k < n) {
                        if (ans[i + k] != 'G') ans[i+k] = 'H';
                        else ans[i+k-1] = 'H';
                        for (int j = i; j <= i + 2*k; j++) if (cows[j] == 'H') used[j] = true;
                    }

                    else {
                        for (int j = n-1; j >= 0; j--) {
                            if (ans[j] != 'G') { ans[j] = 'H'; break; }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) 
                if (ans[i] == 'G' || ans[i] == 'H') ct++;

            cout << ct << endl;

            for (int i = 0; i < n; i++) {
                if (ans[i] == 'G' || ans[i] == 'H') {cout << ans[i];}
                else cout << '.';
            } cout << endl;
        }
    }
}