#include <iostream>

using namespace std;
int solve(int W, int O, int B, int Cow, int Cbo, int Cbw) {
    //white to orange
    int WO = min((W*Cow), (W*(Cbo+Cbw)));
    //white to brown
    int WB = min((W*Cbw), (W*(Cow+Cbo)));

    //orange to white
    int OW = min((O*Cow), (O*(Cbo+Cbw)));
    //orange to brown
    int OB = min((O*Cbo), (O*(Cow+Cbw)));

    //brown to orange
    int BO = min((B*Cbo), (B*(Cow+Cbw)));
    //brown to white
    int BW = min((B*Cbw), (B*(Cow+Cbo)));

    int white = OW + BW;
    int orange = BO + WO;
    int brown = OB + WB;
    return min(min(white, orange), brown);
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int W, O, B, Cow, Cbo, Cbw;
        cin >> W >> O >> B >> Cow >> Cbo >> Cbw;
        cout << solve(W, O, B, Cow, Cbo, Cbw) << '\n';
    }
}
