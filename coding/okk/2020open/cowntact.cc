#include <iostream>
using namespace std;

bool endstate[101], posspz[101], possk[251];
int x, n, t, shake1[251], shake2[251];
int bigk, smallk = 251;
string s;

int works (int zero, int k) {
    bool inf[101] = {0};
    int ct[101] = {0};

    inf[zero] = true;

    for (int i = 0; i <= 250; i++) {
        int x = shake1[i], y = shake2[i];

        if (x > 0) { //if there's a handshake occurring at this time
            if (inf[x]) ct[x]++;
            if (inf[y]) ct[y]++;
            if (ct[x] <= k && inf[x]) inf[y] = true;
            if (ct[y] <= k && inf[y]) inf[x] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (endstate[i] != inf[i]) return false;
    }

    return true;
}

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    cin >> n >> t;

    /*endstate is 1 indexed because we count the cows 
    starting with 1 up to n...*/
    cin >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') endstate[i] = true;
        else endstate[i] = false;
    }

    //for (int i = 1; i <= n; i++) cout << endstate[i] << " ";

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //at time a, cows b and c shook hooves
        shake1[a] = b; shake2[a] = c;
    }

    //loops through possible patient zeros
    for (int i = 1; i <= n; i++) {
        //loops though possible k values
        for (int j = 0; j <= t; j++) {
            if (works(i, j)) {
                //cout << i << " " << j << endl;
                posspz[i] = true; possk[j] = true;
            }
        }
    }

    //count the number of possible pzs
    for (int i = 1; i <= n; i++) if (posspz[i] == 1) x++;
    for (int i = 0; i <= t; i++) if (possk[i]) bigk = i;
    for (int i = t; i >= 0; i--) if (possk[i]) smallk = i;

    cout << x << " " << smallk << " ";
    if (bigk >= t) cout << "Infinity" << endl;
    else cout << bigk << endl;
}