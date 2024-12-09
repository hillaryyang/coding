#include <iostream>
using namespace std;

int n, k, t, a[50][50], ans;
string s;
bool ok;

int s1() {
    ok = true;
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[0][i] == 'H' || a[i][n-1] == 'H') {ok = false; break;}
        else ok = true;
    } if (ok) ans++;

    for (int i = 0; i < n; i++) {
        if (a[i][0] == 'H' || a[n-1][i] == 'H') {ok = false; break;}
        else ok = true;
    } if (ok) ans++;

    return ans;
}

int s2h() {
    ok = true;
    ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[0][i] == 'H') break;
        //checks the vertical move
        for (int j = 0; j < n; j++) {
            if(a[j][i] == 'H') {ok = false; break;}
            else ok = true;
        } if (!ok) continue;
        //checks the last horizontal move
        for (int j = i; j < n - 1; j++) {
            if (a[n-1][j] == 'H') {ok = false; break;}
            else ok = true;
        } //if (!ok) continue;
        if (ok) ans++;
    } 
    return ans;
}

int s2v() {
    ok = true;
    ans = 0;
    for (int i = 1; i < n-1; i++) {
        if (a[i][0] == 'H') break;

        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'H') {ok = false; break;}
            else ok = true;
        } if (!ok) continue;

        for (int j = i; j < n; j++) {
            if (a[j][n-1] == 'H') {ok = false; break;}
            else ok = true;
        } 
        if (ok) ans++;
    }
    return ans;
}

int s3() {
    ok = true; ans = 0; int temp[50][50];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) temp[i][j] = 0;
    }

    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            for (int k = 0; k <= i; k++) temp[0][k] = 1;
            for (int k = 0; k <= j; k++) temp[k][i] = 1; 
            for (int k = i; k < n; k++) temp[n-1][k] = 1;
            for (int k = j; k < n; k++) temp[k][i] = 1;

            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (temp[k][l] == 1 && a[k][l] == 'H') {ok = false; break;}
                    else ok = true;
                } if (!ok) break;
            } if (ok) ans++;

            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) temp[k][l] = 0;
            }

            for (int k = 0; k <= j; k++) temp[0][k] = 1;
            for (int k = 0; k <= i; k++) temp[k][i] = 1;
            for (int k = j; k < n; k++) temp[n-1][k] = 1;
            for (int k = i; k < n; k++) temp[k][j] = 1;

            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (temp[k][l] == 1 && a[k][l] == 'H') {ok = false; break;}
                    else ok = true;
                }
                if (!ok) break;
            }
            
            if (ok) ans++;

            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) temp[k][l] = 0;
            }
        }
    } 
    
    return ans;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) a[i][j] = s[j];
        }

        if (k == 1) cout << s1() << endl;

        else if (k == 2) cout << s1() + s2v() + s2h() << endl;

        else if (k == 3) cout << s3() + s1() + s2v() + s2h() << endl;
    }
}