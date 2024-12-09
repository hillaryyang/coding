#include <iostream>
using namespace std;

int main() {
string s; cin >> s;
long max = 1;
long ct = 1;
for (int i = 0; i < s.length(); i++) {
    if (s[i+1] == s[i]) {
        ct++;
        if (ct > max) max = ct;
    }
    else ct = 1; 
}
cout << max << endl;
}