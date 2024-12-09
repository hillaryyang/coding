#include <iostream>
using namespace std;
char c[26];

int main() {
string s; cin >> s;
int oddct = 0; 
int length = s.length();
for (int i = 0; i < length; i++) c[s[i] - 65]++;
for (int i = 0; i < 26; i++) {
    if (c[i] % 2 == 0) oddct++;
    if (oddct > 1 && length % 2 == 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
}
//if string is even and oddct = 0
if (length % 2 == 0) {
char firsthalf[length/2];
char secondhalf[length/2];
for (int i = 0; i < 26; i++) {
    int toAdd = c[i] / 2;
    for (int j = 0; j < toAdd; j++) {
        firsthalf[i] = (char) (i + 65);
        j = toAdd;
    }
    
}
}


}
