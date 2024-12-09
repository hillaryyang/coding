#include <iostream>
using namespace std;

int b1, b2, s1, s2, g1, g2, p1, p2, bs, sg, gp;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    cin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;

    gp = p2-p1;
    sg = g2+p2-g1-p1;
    bs = g2+p2+s2-s1-g1-p1;

    cout << bs << endl << sg << endl << gp << endl;
}