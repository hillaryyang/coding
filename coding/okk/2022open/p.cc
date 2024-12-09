#include <iostream>
using namespace std;

int n, ans;
string s;
char last = '.';

//backward technique

int main() {
    cin >> n >> s;

    for (int i = n - 1; i >= 0; i -= 2) {
        //if they're the same, doing a flip won't accomplish anything
        if (s[i] == s[i - 1]) continue;

        /*if it's a G only if last is H, then we need to flip 
        notice that this will not add an extra flip at the end
        since last is initialized an arbitrary character*/
        else if (s[i] == 'G' && last == 'H') {ans++; last = 'G';}

        /*otherwise, if the character is H, then we flip regardless of whether
        last is 'G' or '.', it just can't be H*/
        else if (s[i] == 'H' && last != 'H') {ans++; last = 'H';}
    }

    cout << ans << endl;
}