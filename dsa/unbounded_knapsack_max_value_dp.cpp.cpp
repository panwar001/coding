#include<bits/stdc++.h>
using namespace std;

class Solution{
    
    int maxKnapSack(int wt[], int val[], int n, int target, vector<vector<int>> &dp) {
        
        if(n == 0) {
            if(target%wt[n] == 0) {
                    return (target/wt[n])*val[n];
            }
            return 0;
        }
        
        if(dp[n][target] != -1) {
            return dp[n][target];
        }
        
        int notTake = maxKnapSack(wt, val, n-1, target, dp);
        int take = INT_MIN;
        if(wt[n] <= target) {
            take = val[n] + maxKnapSack(wt, val, n, target-wt[n], dp);
        }
        
        return dp[n][target] = max(take, notTake);
        
    }
    
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W+1, -1));
        return maxKnapSack(wt, val, N-1, W, dp);
    }
};

int main() {
    Solution ob;
   // vector<int> wt = {2, 4, 6}; // Weight of items
    int wt[3] = {2, 4, 6};
   // vector<int> val = {5, 11, 13}; // Value of items
    int val[3] = {5, 11, 13};
    int W = 10; // Weight capacity of the knapsack
    int n = 3; // Number of items
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << ob.knapSack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}
