#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int farm[1000][1000];
vector <int> pos;
int cur;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    
    int n; cin >> n;
    int x = 500, y = 500;

    for (int i = 0; i < n; i++) {
        char dir; int num;
        cin >> dir >> num;
        
        if (dir == 'N') {
            for (int j = y + 1; j <= y + num; j++) {
                cur++; 
                if (farm[x][j] == 0) farm[x][j] = cur;
                else pos.push_back(cur - farm[x][j]);
            }
            y += num;
        }

        else if (dir == 'S') {
            for (int j = y - 1; j >= y - num; j--) {
                cur++; 
                if (farm[x][j] == 0) farm[x][j] = cur;
                else pos.push_back(cur - farm[x][j]);
            }
            y -= num;
        }

        else if (dir == 'E') {
            for (int j = x + 1; j <= x + num; j++) {
                cur++; 
                if (farm[j][y] == 0) farm[j][y] = cur;
                else pos.push_back(cur - farm[j][y]);
            }
            x = x + num;
        }

        else if (dir == 'W') {
            for (int j = x - 1; j >= x - num; j--) {
                cur++; 
                if (farm[j][y] == 0) farm[j][y] = cur;
                else pos.push_back(cur - farm[j][y]);
            }
            x = x - num;
        }
    }

    int small = 1000000000;
    for (auto c : pos) small = min(c, small);

    if (small == 1000000000) cout << -1 << endl;
    else cout << small << endl;
}