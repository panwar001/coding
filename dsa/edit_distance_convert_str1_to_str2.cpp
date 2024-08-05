#include<bits/stdc++.h>
using namespace std;

class Solution {
    int eDistance(string str1, string str2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0) return j-i;
        if (j < 0) return i-j;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if (str1[i] == str2[j]) {
            return dp[i][j] = eDistance(str1, str2, i-1, j-1, dp);
        }
        return dp[i][j] = 1 + min(eDistance(str1, str2, i, j-1, dp),
                       min(eDistance(str1, str2, i-1, j, dp),
                       eDistance(str1, str2, i-1, j-1, dp))
                       );

    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return eDistance(word1, word2, n-1, m-1, dp);

        // Tabulation 
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base case , i = -1 -> i = 0, apply 1 based indexing
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];

    }
};

int main() {
  Solution obj;
  cout << "Min distance  " << obj.minDistance("horse","ros") << endl;
}
