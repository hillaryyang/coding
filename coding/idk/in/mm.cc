#include <iostream>
using namespace std;

int day[2][101], d, ct;
string c, a;
bool bon, eon, mon, bonn, eonn, monn;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> d >> c >> a;
        if (c == "Bessie") day[0][d] = 1;
        if (c == "Elsie") day[0][d] = 2;
        if (c == "Mildred") day[0][d] = 3;

        if (a[0] == '+') day[1][d] = a[1] - '0';
        else day[1][d] = -(a[1] - '0');
    }

    int b = 7, e = 7, m = 7;

    for (int i = 0; i < 101; i++) {
        if (day[0][i] != 0) {
            if (day[0][i] == 1) b += day[1][i];
            else if (day[0][i] == 2) e += day[1][i];
            else if (day[0][i] == 3) m += day[1][i];

            int mx = max(b, max(e, m));
            if (mx == b) bonn = true;
            else bonn = false;

            if (mx == e) eonn = true;
            else eonn = false;

            if (mx == m) monn = true;
            else monn = false;

            /*cout << b << " " << e << " " << m << endl;
            cout <<  bon << " " << eon << " " << mon << endl << bonn << " " << eonn << " " << monn << endl;
            cout << endl;*/
        }

        if (bonn != bon || monn != mon || eonn != eon) ct++; 

        bon = bonn; 
        mon = monn;
        eon = eonn;
    }

    cout << ct << endl;
}