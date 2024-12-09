#include <iostream>
using namespace std;

int q;
string a[110];

int main(){
    cin >> q;

    for (int i = 0; i < q; i++) cin >> a[i];

    for(int i = 0; i < q; i++){
        string s = a[i];

        int len = s.size();

        if (len < 3) cout << -1 <<endl;
        
        else if (len == 3){
            if (s == "MOO") cout << 0 << endl;
            else if (s == "OOO") cout << 1 << endl;
            else if (s == "MOM") cout << 1 << endl;
            else if (s == "OOM") cout << 2 << endl;
            else cout << -1 << endl;
        }

        else if (len > 3) {
            int ct = 1000, cur = 1000;
            for (int i = 0; i < len - 2; i++){
                if (s.substr(i, 3) == "MOO"){
                    ct = len - 3; cur = ct; break;
                }
 
                else if (s.substr(i, 3) == "OOO") { 
                    ct = len - 2;
                    if (ct < cur) cur = ct;
                }

                else if (s.substr(i, 3) == "MOM") {
                    ct = len - 2;
                    if (ct < cur) cur = ct;
                }

                else if (s.substr(i, 3) == "OOM") {
                    ct = len - 1;
                    if (ct < cur) cur = ct;
                }
            }

            if (cur == 1000) cout << -1 << endl;
            else cout << cur << endl;
        }
    }
}