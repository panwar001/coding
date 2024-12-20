class Solution {

    // bool checkWord(string s, vector<string>& wordDict, vector<int> &dp, int idx) {
    //     if(idx == s.size()) {
    //         return true;
    //     }

    //     for (int len = 1; len < s.size(); len++) {
    //         string str = s.substr(idx, len);
    //         if(dp[idx] != -1) {
    //             return dp[idx];
    //         }
    //       //   Main logic
    //         if (set.find(str) != set.end() && checkWord(s, wordDict, dp, idx+len)) {
    //             return dp[idx] = true;
    //         }
    //     }
    //     return dp[idx] = false;
    // }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
    
        unordered_set<string> set(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        // tabulation - 
        for(int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string str = s.substr(j, i-j);
                if (set.count(str) && dp[j]) {
                   dp[i] = true;
                   break;
                }
            }
        }
        return dp[n];
    }
};
