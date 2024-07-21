// C++ Implementation of fruits in two basket sliding window code
#include <bits/stdc++.h>
using namespace std;
 
int characterReplacement(string S, int K) {
        // code here
        int l=0;
        int r=0;
        int maxlen=0;
        int maxf=0; //max frequency
        int n=S.size();
        unordered_map<char,int>mp;
        while(r<n)
        {
            mp[S[r]]++;
            maxf=max(maxf,mp[S[r]]);
            while((r-l+1)-maxf>K)
            {
                mp[S[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }

// Driver code
int main()
{
    // Function call
    cout << characterReplacement("AABABBA", 1);
    return 0;
}
