#include <bits/stdc++.h>

using namespace std;

// 0 1 Knapsack 
int knapsack(vector<int> weight, vector<int> values, int n, int maxWeight, vector<vector<int>> dp) {
    if (n == 0 || maxWeight == 0 )  {
        return 0;
    }

    // not taken
    if (dp[n][maxWeight] != -1) {
        return dp[n][maxWeight];
    }
    
    int notTaken = knapsack(weight, values, n-1, maxWeight, dp);
    
    // taken
    int taken = 0;
    if (weight[n-1] <= maxWeight) {
      taken = values[n-1] + knapsack(weight, values, n-1, maxWeight-weight[n-1], dp);
    } 

    dp[n][maxWeight] =  max(taken, notTaken);

    return dp[n][maxWeight];
    
}

int main() {
    std::cout << "0/1 Knapsack problem" << std::endl;

    // weight
    vector<int> weight{ 1, 2, 4, 5};
    vector<int> values{ 5, 4, 8, 6};
    
    int maxWeight = 9;
    int n = 4;

    // initialise a dp 2d array with size [n][W+1]
    // The size of the input array is ‘N’, so the index will always lie between ‘0’ and ‘n-1’. 
   // The capacity can take any value between ‘0’ and ‘W’. Therefore we take the dp array as dp[n][W+1]
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));

    int maxValue = knapsack(weight, values, n-1, maxWeight, dp);
    cout << "max value possible - " << maxValue;
    
    return 0;
}
