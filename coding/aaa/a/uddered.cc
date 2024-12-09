#include <iostream>
using namespace std;

string alphabet, hummed, l;
char cur;
bool used[100];

int main() {
    cin >> alphabet >> hummed;

    int n = hummed.length();

    for (int i = 0; i < n; i++) l += alphabet;

    int i = 0;
    for (int j = 0; j < l.size(); j++) {
        if (l[j] == hummed[i]) {
            if (i != n-1) i++;
            else {cout << j/26 +1 << endl; return 0;}
        }
    }    
}