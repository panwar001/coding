#include<bits/stdc++.h>
using namespace std;

class Solution {
    int coinChangeDP(vector<int>& coins, int n, int amount, vector<vector<int>> &dp) {

        // amount == 0 check is not applicable here check with example {2,3,4,1}, amount  9       
        // Base case
        if(n == 0) {
            if(amount%coins[n]== 0) {
                return amount/coins[n];
            } 
            return 1e9;
        }
        if(dp[n][amount] != -1) {
            return dp[n][amount];
        }
        int notPick = coinChangeDP(coins, n-1, amount, dp);
        int pick = 1e9;
        if(coins[n] <= amount) {
            pick = 1 + coinChangeDP(coins, n, amount-coins[n], dp);
        }
        return dp[n][amount] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int res = coinChangeDP(coins, n-1, amount, dp);
        // if (res >= 1e9) {
        //     return -1;
        // } else {
        //     return res;
        // }
        // Tabulation method
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for (int i = 0; i < n; i++) {
            for(int amt = 0; amt <= amount; amt++) {
                if(i == 0) { // base case, amt can range from 0 amount
                    if (amt%coins[i] == 0) {
                        dp[i][amt] = amt/coins[i];
                    }else {
                        dp[i][amt] = 1e9;
                    }
                } else {
                    int notPick = dp[i-1][amt];
                    int pick = 1e9;
                    if(coins[i] <= amt) {
                        pick = 1 + dp[i][amt-coins[i]];
                    }
                    dp[i][amt] = min(pick, notPick);
                }
            }
        }
        if(dp[n-1][amount] >= 1e9) {
            return -1;
        }
        return dp[n-1][amount];
        
    }
};

int main() {
  Solution ob;
  vector<int> coins{1,2,5};
  int amount = 11;
  cout<< "Minium coins required " << ob.coinChange(coins, amount) << endl;
}
