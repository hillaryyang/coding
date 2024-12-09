#include <iostream>
#include <vector>
using namespace std;

int n, area, maxarea; 

int main() {

    //freopen("triangles.in", "r", stdin);
	//freopen("triangles.out", "w", stdout);
    
    cin >> n;

    vector<int> X(n, 0);
    vector<int> Y(n, 0);

    for (int i = 0; i < n; i++) cin >> X[i] >> Y[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (Y[i] == Y[j] && X[i] == X[k]) {
                    area = (Y[k] - Y[i]) * (X[j] - X[i]);
                    if (area < 0) area *= -1;
                    if (area > maxarea) maxarea = area;
                }
            }
        }
    }
    cout << maxarea << endl;
}