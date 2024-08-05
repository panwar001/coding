class Solution {
    int f(vector<int>& prices, int i, int buy, vector<vector<int>> &dp) {
        if(i == prices.size()) {
            return 0;
        }
        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int profit = 0;
        if(buy) { // buy condition
            profit = max((-prices[i] + f(prices, i+1, 0, dp)),
                f(prices, i+1, 1, dp));
        } else { // sell condition
            profit = max(prices[i] + f(prices, i+1, 1, dp), f(prices, i+1, 0, dp));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // buy flag can have two values, 0, 1
        // vector<vector<int>> dp(n, vector<int>(2,-1));
        // return f(prices, 0, 1, dp);

        // tabulation method
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        // base condition if n == ind
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy) {
                    profit = max((-prices[i]+dp[i+1][0]), dp[i+1][1]);
                } else {
                    profit = max((prices[i]+dp[i+1][1]), dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
