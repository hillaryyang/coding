//http://www.usaco.org/index.php?page=viewproblem2&cpid=1324
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int N, C, P, mx = 0; cin >> N >> C >> P;
        vector<string> n, iv, tv, c;
        vector<int> x(4);

        for (int i = 0; i < N; i++) {
            string a, b; cin >> a >> b;
            if (b == "noun") n.push_back(a);
            else if (b == "transitive-verb") tv.push_back(a);
            else if (b == "intransitive-verb") iv.push_back(a);
            else if (b == "conjunction") c.push_back(a);
        }

        int nn = n.size(), tn = tv.size(), in = iv.size(), cn = c.size();
        //cout << nn << " " << tn << " " << in << " " << cn << endl;

        for (int t1 = 0; t1 <= in; t1++) {
            for (int t2 = 0; t2 <= tn; t2++) {
                if ((t1 == 0 && t2 == 0) || t1 + 2 * t2 > nn) continue;

                //total number of sentences, conjunction count, noun count/commas
                int T = t1 + t2, J = min(cn, T/2), M = min(nn - (t1 + 2 * t2), C), W = 2 * t1 + 3 * t2 + J + M;

                //we need T-J periods
                if (T - J > P) continue;

                if (W > mx) {
                    mx = W;
                    x.clear();
                    x[0] = t1, x[1] = t2, x[2] = J, x[3] = M;
                }
            }
        }

        //for (int i : x) cout << i << " "; cout << endl;

        cout << mx << endl;

        //construct the sentences
        int t1 = x[0], t2 = x[1], j = x[2], m = x[3];
        vector<vector<string> > s(t1 + t2);

        //cout << t1 << " " << t2 << " " << j << " " << m << endl;
        /*for (string i : n) cout << i << " "; cout << endl;
        for (string i : tv) cout << i << " "; cout << endl;
        for (string i : iv) cout << i << " "; cout << endl;
        for (string i : c) cout << i << " "; cout << endl;*/
        
        //type 1 sentences; noun iv
        for (int i = 0; i < t1; i++) {
            s[i].push_back(n.back()); s[i].push_back(iv.back());
            n.pop_back(); iv.pop_back();
        }

        //type 2 sentences; noun tv noun
        for (int i = 0; i < t2; i++) {
            s[t1 + i].push_back(n.back()); s[t1 + i].push_back(tv.back()); 
            n.pop_back(); tv.pop_back();
            s[t1 + i].push_back(n.back()); n.pop_back();
        }

        /*for (int i = 0; i < s.size(); i++) {
            for (string j : s[i]) cout << j << " ";
           cout << endl;
        }*/

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            for (string j : s[i]) ans += (j + " ");
            //add conjunctions
            if (i % 2 == 0 && j) { j--; ans += c.back() + " "; c.pop_back(); }
            else {ans.pop_back(); ans += ". ";}
        }

        //tack on the nouns at the end of the last sentence (t2)
        if (ans != "") ans.pop_back(); //removes space
        
        if (m > 0) {
            ans.pop_back(); //removes period
            while (m > 0) {
                ans += ", " + n.back(); n.pop_back(); m--;
            }

            ans += ".";
        }

        cout << ans << endl;
    }
}