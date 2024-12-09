#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

string cow, hum, temp;
int ct, lastpos;

int main() {
    cin >> cow >> hum;

    reverse(hum.begin(), hum.end());

    for (int i = 0; i < hum.length(); i++) temp += cow;

    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == hum[hum.length() - 1]) {
            //cout << i << endl;
            hum.pop_back();
            if (hum.empty()) {lastpos = i; break;}
        }
    }

    cout << ceil((double)lastpos/26) << endl;
}