#include <iostream>
using namespace std;

int strToInt(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '"') cout << (int)str[i] - 48;
    }
    cout << endl;
}

int main() {
string s; cin >> s;
strToInt(s);
}