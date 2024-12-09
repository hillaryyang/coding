#include <iostream>
using namespace std;

bool check(string a, string b) {
    a += a;
    if (a.find(b) != string::npos) return true;
    else return false;
}

int main() {
string a, b; cin >> a >> b;
if (a.size() < b.size()) a.swap(b);
if (check(a, b)) cout << "true" << endl;
else cout << "false" << endl;
}