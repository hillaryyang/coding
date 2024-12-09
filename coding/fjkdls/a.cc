#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int t; cin >> t;
    while (t--) {
        vector<string> no, tv, iv, conj;
        int n, c, p;
        cin >> n >> c >> p;

        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            if (b == "noun") no.push_back(a);
            else if (b == "transitive-verb") tv.push_back(a);
            else if (b == "intransitive-verb") iv.push_back(a);
            else if (b == "conjunction") conj.push_back(a);
        }

        //the number of sentences you can make
        int v = min((int)no.size(), min((int)iv.size(), p));

        int mx = 2 * v + min((int)conj.size(), v/2);
        int things = mx;

        string ans[10000];
        ans[0] = "n";
        int ct = conj.size();

        for (int i = 1; i < things; i++) {
            if (ans[i - 1] == "n") ans[i] = "iv";
            else if (ans[i - 1] == "iv") {
                if (ct == 0 || ans[i - 3] == "c") {ans[i] = "."; things++;}
                else {ans[i] = "c"; ct--;}
            }
            else if (ans[i - 1] == "c") ans[i] = "n";
            else ans[i] = "n";

            //cout << i << " " << ans[i] << endl;
        }

        /*for (int i = 0; i < mx; i++) cout << ans[i] << " "; 
        cout << endl;*/

        cout << mx << endl;

        if (mx == 0) {cout << endl; continue;}

        for (int i = 0; i < things - 1; i++) {
            if (ans[i] == "n") {cout << no.back() << " "; no.pop_back();}
            else if (ans[i] == "iv") {
                if (ans[i+1] == ".") cout << iv.back(); 
                else cout << iv.back() << " ";
                iv.pop_back();
            }
            else if (ans[i] == "c") {cout << conj.back() << " "; conj.pop_back();}
            else {cout << ". "; p--;}
        }
        
        cout << iv.back() << "." << endl;

        //cout << v << endl << mx << endl;
    }
}