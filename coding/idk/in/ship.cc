#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

string s;

int main() {
    cin >> s;

    int x = 0, y = 0;

    for (int i = 0; i < (int)s.length(); i++) {
        int ct = 1;
        for (int j = i; j < (int)s.length(); j++) {
            if (s[j] == s[j + 1]) ct++;
            else break;
        }

        cout << ct << endl;

        if (ct == 1) {
            //cout << x << " " << y << endl;
            if (s[i] == 'v') y-=2;
            else if (s[i] == '^') y+=2;
            else if (s[i] == '>') x+=2;
            else if (s[i] == '<') x-=2;
        }

        else if (ct == 2) {
            if (s[i] == 'v') y-=4;
            if (s[i] == '^') y+=4;
            if (s[i] == '>') x+=4;
            if (s[i] == '<') x-=4;

            i ++;
        }

        else {
            int dif = 20;
            for (int j = 0; j < ct - 3; j++) dif += 5;

            if (s[i] == 'v') y-=dif;
            if (s[i] == '^') y+=dif;
            if (s[i] == '>') x+=dif;
            if (s[i] == '<') x-=dif;

            i += ct - 1;
        }
    }

    cout << "(" << x << "," << y << ")" << endl;
}