#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

long long nthFibonacci(int n){
    // Handle the edge cases
    if (n <= 1)
        return n;

    // Create a vector to store Fibonacci numbers
    vector<int> dp(n + 1);

    // Initialize the first two Fibonacci numbers
    dp[0] = 0;
    dp[1] = 1;

    // Fill the vector iteratively
    for (int i = 2; i <= n; ++i){

        // Calculate the next Fibonacci number
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the nth Fibonacci number
    return dp[n];
}

const long long N = 1e9 + 7;
int main() {
    for (int i = 0; i <= 99; i++){
        string filename = "input" + (i < 10 ? "0" + to_string(i) : to_string(i)) + ".txt";
        ifstream myfile;
        myfile.open(filename);

        int a;
        while (myfile >> a) {
            long long x = pow(nthFibonacci(a), 2);

            string outfile = "output" + (i < 10 ? "0" + to_string(i) : to_string(i)) + ".txt";
            ofstream output;
            output.open(outfile);
            output << x % N;
            output.close();
        }

        myfile.close();
    }
}