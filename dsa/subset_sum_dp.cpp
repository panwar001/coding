#include<bits/stdc++.h>
using namespace std;

class Solution{   
    // recursive and memoization approach
    bool isSubsetSumDP(vector<int> &arr, int n, int sum, vector<vector<int>> &dp) {
        if (sum == 0) {
            return 1;
        }
        if (n == 0) {
            if (sum == arr[n]) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        
        bool notTake = isSubsetSumDP(arr, n-1, sum, dp);
        bool take = false;
        if (arr[n] <= sum) {
            take = isSubsetSumDP(arr, n-1, sum-arr[n], dp);
        }
        return dp[n][sum] = take||notTake;
        
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1,false));
        
        for(int i= 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        
        // recursive approach
        //return isSubsetSumDP(arr, n-1 , sum, dp);
        
        // tabulation approach
        for(int i = 1; i < n; i++) {
            for(int target = 1; target <= sum; target++) {
                
                int notTake = dp[i-1][target];
                int take = false;
                if(arr[i] <= target) {
                    take = dp[i-1][target-arr[i]];
                }
                dp[i][target] = notTake | take;
            }
        }
        return dp[n-1][sum];
        
        
    }
};

int main() {
  Solution ob;
  vector<int> arr{3, 34, 4, 12, 5, 2};
  int sum = 9;
  cout << ob.isSubsetSum(arr, sum) << endl;

  return 0;
}
