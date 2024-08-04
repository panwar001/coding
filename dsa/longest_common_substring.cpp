// recursive without memoization
class Solution {
    
    int lcss(string s1, string s2, int i, int j, int mx) {
        if(i < 0 || j < 0) {
            return mx;
        }
        if(s1[i] == s2[j]) {
            mx =  lcss(s1, s2, i-1, j-1, mx + 1);
        } 
        int maxx =  max(lcss(s1, s2, i-1, j, 0), lcss(s1, s2, i, j-1, 0));
        maxx = max(mx, maxx);
        return maxx;
        
    }
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int mx = 0;
        return lcss(s1, s2, s1.size()-1, s2.size()-1, mx);
    }
};

// tabulation method
class Solution {
    
  public:
    int longestCommonSubstr(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

       for(int i= 0; i <= n; i++) {
           dp[i][0] = 0;
       }
       for(int j= 0; j <= m; j++) {
           dp[0][j] = 0;
       }
       
       int maxx = 0;
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= m; j++) {
               if(s1[i-1] == s2[j-1]) {
                   dp[i][j] = 1 + dp[i-1][j-1];
                   maxx = max(maxx, dp[i][j]);
               } else {
                   dp[i][j] = 0;
               }
           }
       }
       return maxx;
    }
};
