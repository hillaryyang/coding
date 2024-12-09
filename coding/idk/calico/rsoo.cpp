#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/**
 * Determine if the RSO name for an entry is valid. Return True if it is and
 * return False otherwise.
 * 
 * Y: the year the RSO was established
 * N: the name the RSO registered with
 */
bool solve(int Y, string n) {
    if (n.length() > 50) return false; 

    else if (n.length() <= 50) {
        string firstword = n.substr(0, n.find(" "));
        for (int i = 0; i < firstword.length(); i++) firstword[i] = tolower(firstword[i]);
        if (Y >= 2010) {
            if (firstword == "california") return false;
            else if (firstword == "cal") return false;
            else if (firstword == "berkeley") return false;
            else return true;
        }
        else return true;
    }
    else return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int Y;
        cin >> Y;
        cin.ignore();
        string N;
        getline(cin, N);
        cout << (solve(Y, N) ? "VALID" : "INVALID") << '\n';
    }
}
