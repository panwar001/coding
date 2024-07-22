#include <bits/stdc++.h>
using namespace std;

int fibonacciSeries(int n, vector<int> &dp) {
    if (n <= 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }
    
    return dp[n] =  fibonacciSeries(n-1, dp) + fibonacciSeries(n-2, dp);
}

int main() {
    std::cout << "Hello Fibonacci!" << std::endl;

    int n = 5;

    vector<int> dp(n+1, -1);
    cout << fibonacciSeries(n, dp);
    
    return 0;
}
