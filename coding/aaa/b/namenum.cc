/*
ID: hillary3
TASK: namenum
LANG: C++                 
*/


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

long long n;
char arr;
string myText;
vector<string> names, works;

char convert(char a) {
    if (a == 'A' || a == 'B' || a == 'C') return '2';
    else if (a == 'D' || a == 'E' || a == 'F') return '3';
    else if (a == 'G' || a == 'H' || a == 'I') return '4';
    else if (a == 'J' || a == 'K' || a == 'L') return '5';
    else if (a == 'M' || a == 'N' || a == 'O') return '6';
    else if (a == 'P' || a == 'R' || a == 'S') return '7';
    else if (a == 'T' || a == 'U' || a == 'V') return '8';
    else if (a == 'W' || a == 'X' || a == 'Y') return '9';
    return '0';
}
 

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    ifstream MyReadFile("dict.txt");\

    while (getline (MyReadFile, myText)) names.push_back(myText);

    cin >> n; 
    string s = to_string(n);

    //cout << s << endl;

    for (int i = 0; i < names.size(); i++) {
        string newstr = "", temp = names[i];
        for (int j = 0; j < temp.size(); j++) {newstr += convert(temp[j]);}

        if (s == newstr) works.push_back(names[i]);
    }
    
    if (works.empty()) cout << "NONE" << endl;
    else {
        for (auto c : works) cout << c << endl;
    }
}