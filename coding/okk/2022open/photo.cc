#include <iostream>
using namespace std;

int n, ans, last = -1;
string s;

int main() {
    cin >> n >> s;

    //similarly, we go through the even locations
    for (int i = 0; i < n; i += 2) {
        //if they're the same, continue
        if (s[i] == s[i + 1]) continue;

        /*if s[i] == 'G', then we check if the last character was 
        a 'G', given by 0, and 'H', given by 1.
        if last != 0, then, we will add a flip
        */
        else if (s[i] == 'G' && last != 0) {ans++; last = 0;}

        //similar logic 
        else if (s[i] == 'H' && last != 1) {ans++; last = 1;}
    }

    //if last was 1, we subtract 1
    if (last == 1) ans--;

    cout << ans << endl;
}