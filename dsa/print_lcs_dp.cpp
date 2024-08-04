#include <bits/stdc++.h>
using namespace std;

class Solution {
    
  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<string> res;
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        for(int i= 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << "length lcs " << dp[n][m] << endl;
        // print lcs using dp array
        int i = n;
        int j = m;
        string str = "";
        while(i > 0 && j > 0) {
            if(s[i-1] == t[j-1]) {
               str = s[i-1] + str;
                i--;
                j--;
            } else if (s[i-1] > t[j-1]) {
                i--;
            } else {
                j--;
            }
        }
        cout << str << endl;
        res.push_back(str);
        return res;
    }
};

int main(){
    Solution obj;
    vector<string> lcs = obj.all_longest_common_subsequences("abcde", "bcdet");
    int len = lcs.size();
    cout << "LCS " << len << endl;
}
