#include <iostream>
#include <vector>

using namespace std;

int solve(int N, int B, int W, int D, vector<int> H) {
    int shelf = W * B * D * (N+1);
    //cout << "Shelf : " << shelf << endl;
    int blank = 0;
    for (int i = 0; i < H.size(); i++) blank += H[i];
    //cout << "Blank : " << blank << endl;
    int h = (N+1)*B + blank;
    //cout << "h : " << h << endl;
    int side = B * D * 2*h;
    //cout << "Side : " << side << endl;
    return side + shelf;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, B, W, D;
        cin >> N >> B >> W >> D;

        vector<int> H(N);
        for (int &height: H) {
            cin >> height;
        }

        cout << solve(N, B, W, D, H) << '\n';
    }
    return 0;
}
