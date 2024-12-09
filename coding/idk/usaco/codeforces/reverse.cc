#include <iostream>
using namespace std;

int n, m;
int out[101], b[101][101];

bool emp() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (b[j][i] != -1) return false;
    }

    return true;
}

int main() {
    int t; cin >> t;

    while (t--) {
        cin >> n >> m;
        
        for (int i = 0; i < m; i++) {
            string s; cin >> s; cin >> out[i];
            for (int j = 0; j < n; j++) b[i][j] = s[j] - '0';
        }

        //for (int i = 0; i < m; i++) cout << out[i] << endl;

        bool a = false, bb = false;
        while (true) {
            bool x = false;
            //loop over columns
            for (int i = 0; i < n; i++) {
                bool o = true, z = true, f1 = true, f0 = true;
                int loc1 = 0, loc2 = 0;

                //loop over elements of this column
                for (int j = 0; j < m; j++) {
                    if (b[j][i] == 1 && f1) {f1 = false; loc1 = out[j];}
                    else if (b[j][i] == 0 && f0) {f0 = false; loc2 = out[j];}

                    if (b[j][i] == 1 && out[j] != loc1) o = false;
                    else if (b[j][i] == 0 && out[j] != loc2) z = false;
                }

                if (f1) o = false; 
                if (f0) z = false;

                if (o) {
                    for (int j = 0; j < m; j++) {
                        if (b[j][i] == 1) {for (int k = 0; k < n; k++) b[j][k] = -1; out[j] = -1;}
                    }
                }

                if (z) {
                    for (int j = 0; j < m; j++) {
                        if (b[j][i] == 0) {for (int k = 0; k < n; k++) b[j][k] = -1; out[j] = -1;}
                    }
                }

                if (o || z) x = true;
            }

            if (emp() || !x) break;
        }

        if (emp()) cout << "OK" << endl;
        else cout << "LIE" << endl;
    }
}