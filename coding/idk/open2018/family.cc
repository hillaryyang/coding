//http://www.usaco.org/index.php?page=viewproblem2&cpid=833
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define pb push_back
#define f first 
#define mp make_pair
using namespace std;

int n; string a, b, x, y;
map<string, string> mom;

string out(string a, string b, string rel, int ct) {
    string ans = "";
    ans += a; ans += " is the ";
    for (int i = 0; i < ct - 1; i++) ans += "great-";
    if (ct > 0) ans += "grand-"; 
    ans += rel; ans += " of "; ans += b;

    return ans;
}

int direct(string a, string b) {
    //checks if a is a direct older of b
    string cur = b; int gct = 0; bool flag = false;
    while (cur != "") {
        //cout << cur << endl;
        if (cur == a) return gct - 1;
        cur = mom[cur]; gct++;
    }

    return -1;
}

int aunt(string a, string b) {
    //checks if a is aunt of b
    string cur = b, p; int gct = 0;
    while (cur != "") {
        cur = mom[cur]; gct++;
        if (gct > 1 && mom[a] == cur && cur != "") return gct - 1;
    }

    return -1;
}

bool cousins(string a, string b) {
    //go up the family line of a
    string cur = a;
    while (cur != "") {
        cur = mom[cur];
        if (direct(cur, b) != -1 || direct(b, cur) != -1) return true;
    }

    return false;
}

int main() {
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        cin >> x >> y; mom[y] = x;
    }

    //check if sister
    if (mom[a] == mom[b]) cout << "SIBLINGS" << endl;
    
    //check if direct
    else if (direct(a, b) != -1) cout << out(a, b, "mother", direct(a, b)) << endl;
    else if (direct(b, a) != -1) cout << out(b, a, "mother", direct(b, a)) << endl;

    //check if aunt
    else if (aunt(a, b) != -1) {
        cout << a << " is the ";
        for (int i = 0; i < aunt(a, b) - 1; i++) cout << "great-";
        cout << "aunt of " << b << endl;
    }

    else if (aunt(b, a) != -1) {
        cout << b << " is the ";
        for (int i = 0; i < aunt(b, a) - 1; i++) cout << "great-";
        cout << "aunt of " << a << endl;
    }

    //check if cousins
    else if (cousins(a, b) || cousins(b, a)) cout << "COUSINS" << endl;
    else cout << "NOT RELATED" << endl;
}