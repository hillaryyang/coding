#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

/**
  * Output the number of times each user is pinged in the server after
  * all actions.
  * 
  * Q: the total number of actions
  * N: the number of roles in the server
  * M: the number of users in the server
  * X: the list of actions performed at each timestep
  * R: the list of roles involved at each timestep
  * U: the list of users involved at each timestep, or -1 if the action is a ping
  */
void solve (int q, int n, int m, vector<char> x, vector<int> r, vector<int> u) {
    unordered_map <int, vector<int> > roles;
    int pingct[N];
    memset(pingct, 0, sizeof(pingct));

    for (int i = 0; i < q; i++) {
        if (x[i] == 'A') {roles[r[i]].push_back(u[i]);}

        else if (x[i] == 'R') {
            roles[r[i]].erase(remove(roles[r[i]].begin(), roles[r[i]].end(), u[i]), roles[r[i]].end());
        }
        else {
            //r[i] is the pinged role
            for (int user : roles[r[i]]) pingct[user]++;
        }
    }

    for (int i = 1; i <= m; i++) cout << pingct[i] << ' ';
    cout << endl;
    /*for (int i = 0; i < M - 1; i++) cout << pingct[i] << " ";
    cout << pingct[M-1] << endl;*/

}

int main () {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int Q, N, M;
        cin >> Q >> N >> M;
        vector<char> X(Q);
        vector<int> R(Q);
        vector<int> U(Q);
        for (int j = 0; j < Q; ++j) {
            cin >> X[j];
            if (X[j] == 'P') {
                cin >> R[j];
                U[j] = -1;
            }
            else {
                cin >> R[j] >> U[j];
            }
        }
        solve(Q, N, M, X, R, U);
    }
}