/*
ID: hillary3
TASK: gift1
LANG: C++                 
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

string giver, ppl, p[10];
int n, amt, num, ans[10];
vector <string> gaveto;
map <string, int> ma;

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    
    cin >> n;

    for (int i = 0; i < n; i++) {cin >> p[i]; ma[p[i]] = i;}

    for (int j = 0; j < n; j++) {
        cin >> giver >> amt >> num;
        for (int i = 0; i < num; i++) {cin >> ppl; gaveto.push_back(ppl);}
        
        if (num == 0) continue;
        
        int receive = floor(amt/num);
        ans[ma[giver]] += -1 * receive * num; 

        for (int i = 0; i < gaveto.size(); i++) ans[ma[gaveto[i]]] += receive;

        gaveto.clear();
    }

    for (int i = 0; i < n; i++) cout << p[i] << " " << ans[i] << endl;
}