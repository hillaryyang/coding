#include <iostream>
using namespace std;

char farm[10][10];
int bx, by;
string s;

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> s;
        for (int j = 0; j < 10; j++) {
            farm[i][j] = s[j];
            if (farm[i][j] = 'B') {bx = i; by = j;}
        }
    }
}