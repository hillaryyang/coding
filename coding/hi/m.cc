#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cow[3][101], day, big, b = 7, e = 7, m = 7, change;
string c, a;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> day >> c >> a;
        cow[0][day] = 1;

        if (c == "Bessie") cow[1][day] = 0;
        else if (c == "Elsie") cow[1][day] = 1;
        else if (c == "Mildred") cow[1][day] = 2;

        if (a[0] == '+') cow[2][day] = stoi(a.substr(1));
        else cow[2][day] = (-1) * stoi(a.substr(1));
    }

    bool bon = true, eon = true, mon = true, bonn = true, eonn = true, monn = true;

    for (int i = 1; i <= 100; i++) {
        if (cow[0][i] > 0) {
            if (cow[1][i] == 0) b += cow[2][i];
            else if (cow[1][i] == 1) e += cow[2][i];
            else m += cow[2][i];

            big = max(max(b, e), m);

            bonn = (b == big);
            monn = (m == big);
            eonn = (e == big);

            if (mon != monn || eon != eonn || bon != bonn) change++;

            mon = monn;
            bon = bonn;
            eon = eonn;
            big = 7;
        }
    }  

    cout << change << endl;
}