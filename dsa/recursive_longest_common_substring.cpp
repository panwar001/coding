lass Solution {
    
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
      //  return mx;
    }
};
