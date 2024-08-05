class Solution {
        int f(vector<int>& prices, int i, int buy, vector<vector<vector<int>>> &dp, int limit) {
        if(limit == 0) {
            return 0;
        }
        if(i == prices.size()) {
            return 0;
        }
        if(dp[i][buy][limit] != -1) {
            return dp[i][buy][limit];
        }
        int profit = 0;
        if(buy) { // buy condition
            profit = max((-prices[i] + f(prices, i+1, 0, dp, limit)),
                f(prices, i+1, 1, dp, limit));
        } else { // sell condition
            profit = max(prices[i] + f(prices, i+1, 1, dp, limit-1), 
                f(prices, i+1, 0, dp, limit));
        }
        return dp[i][buy][limit] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // buy flag can have two values, 0, 1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return f(prices, 0, 1, dp, k);
    }
};
