#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int id[103], updates[103];

int main() {

    freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

    int b = 7, m = 7, e = 7, changes = 0, big = 7, t;
    bool bon = true, mon = true, eon = true, bonn = false, eonn = false, monn = false;
    
    cin >> t;

while (t--) {
    int day, inc, cow; string oldcow, c;
    cin >> day >> oldcow >> c;

    if (oldcow == "Bessie") cow = 1;
    else if (oldcow == "Mildred") cow = 2;
    else if (oldcow == "Elsie") cow = 3;    id[day-1] = cow;

    if (c[0] == '+') inc = stoi(c.substr(1));
    else inc = -1 * stoi(c.substr(1));

    updates[day-1] = inc;
}

for (int i = 0; i < 103; i++) {
        if (id[i] > 0) {
            if (id[i] == 1) b += updates[i];
            else if (id[i] == 2) m += updates[i]; 
            else e += updates[i];

            big = max(max(b, m), e); 
            
            bonn = (b == big); //if bessie has highest, then she's next
            eonn = (e == big);
            monn = (m == big);

            //if (i == 0) cout << bonn << " " << eonn << " " << monn << " " << b << " " << e << " " << m << " " << big << endl;

            if (bonn != bon || monn != mon || eonn != eon) changes ++;
            
            bon = bonn;
            eon = eonn;
            mon = monn;
            big = 7;
        }
    }
cout << changes << endl;
}
