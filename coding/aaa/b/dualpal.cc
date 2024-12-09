/*
ID: hillary3
TASK: dualpal
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
string res;
vector <int> works;

char re(long long n) {
    if (n >= 0 && n <= 9) return (char) (n + '0');
    else return (char)(n - 10 + 'A');
}

string tobase(int n, int b) {
    res = "";
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

bool ok(int a) {
    int basect = 0;
    for (int i = 2; i <= 10; i++) {
        if (pal(tobase(a, i))) basect++;
    }

    return basect >= 2;
}


int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    cin >> n >> s;

    for (int i = s + 1; i < 20000; i++) {
        if (ok(i)) works.push_back(i);

        if (works.size() == n) {
            for (auto c : works) cout << c << endl;
            return 0;
        }
    }
}