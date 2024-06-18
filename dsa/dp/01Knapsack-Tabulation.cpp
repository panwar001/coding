#include <bits/stdc++.h>

using namespace std;

// 0 1 Knapsack Bottom up approach
int knapsack(vector<int> &weight, vector<int> &values, int n, int maxWeight, vector<vector<int>> &dp) {
    
    // Fill the first row for the weight of the first item - base condition
    for (int i = weight[0]; i <= maxWeight; i++) {
        dp[0][i] = values[0];
    }

    // Now as first row is done, iterate over from 2nd row 
    for (int i = 1; i < n; i++) {
        for (int cap = 0; cap <= maxWeight; cap++) {
            // calculate the max value either by including or excluding current item
            int notTaken = 0 + dp[i-1][cap];
            int taken = INT_MIN;

            if(weight[i] <= cap) {
                taken = values[i] + dp[i-1][cap-weight[i]];
            }

            dp[i][cap] = max(taken, notTaken);
            
        }
    }

    // print the DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            cout << dp[i][j] << " ";
        }
    cout << "\n";
    }
    
    return dp[n-1][maxWeight];
    
}

int main() {
    std::cout << "0/1 Knapsack problem Tabulation solution" << std::endl;

    // weight
    vector<int> weight{ 1, 2, 4, 5};
    vector<int> values{ 5, 4, 8, 6};
    
    int maxWeight = 5;
    int n = 4;

    // initialise a dp 2D array with size [n][W+1]
    // The size of the input array is ‘N’, so the index will always lie between ‘0’ and ‘n-1’. 
    // The capacity can take any value between ‘0’ and ‘W’. Therefore we take the dp array as dp[n][W+1]
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

    int maxValue = knapsack(weight, values, n, maxWeight, dp);
    cout << "max value possible - " << maxValue;
    
    return 0;
}
