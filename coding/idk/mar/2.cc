#include <iostream>
#include <vector>
using namespace std;

int t, n, comma, period;
string a, b;
vector<string> noun, tv, iv, con, sentence;

int main() {   
    cin >> t;
    while (t--) {
        cin >> n >> comma >> period;

        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (b == "noun") noun.push_back(a);
            else if (b == "transitive-verb") tv.push_back(a);
            else if (b == "intransitive-verb") iv.push_back(a);
            else if (b == "conjunction") con.push_back(a);
        }

        if (noun.empty() || tv.empty() || iv.empty()) cout << 0 << endl;
        else {
            sentence.push_back(noun[noun.size() - 1]);
            noun.pop_back();
            
        }
    }
}