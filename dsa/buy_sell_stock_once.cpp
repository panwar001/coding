class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX; 
        int profit = 0;
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++) {
            profit = prices[i]-mini;
            maxProfit = max(profit, maxProfit);
            mini = min(prices[i], mini);
        }
        return maxProfit;
    }
};
