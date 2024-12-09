/*
ID: hillary3
TASK: palsquare
LANG: C++                 
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int b;
string res;

char re(long long n) {
    if (n >= 0 && n <= 9) return (char) (n + '0');
    else return (char)(n - 10 + 'A');
}

string tobase(long long n, long long b) {
    int ind = 0;

    while (n > 0) {
        res.push_back(re(n % b));
        ind++; n /= b;
    }

    reverse(res.begin(), res.end());

    return res;
}

bool pal(string a) {
    string temp = a;
    reverse(a.begin(), a.end());

    if (temp == a) return true;
    return false;
}

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    cin >> b;

    for (int i = 1; i <= 300; i++) {
        long long square = i * i;
        string t = tobase(square, b);

        res = "";

        //cout << t << " " << stoi(t) << endl;

        if (pal(t)) {cout << tobase(i, b) << " " << t << endl;}
        res = "";
    }
}

