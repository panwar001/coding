// C++ Implementation of fruits in two basket sliding window code
#include <bits/stdc++.h>
using namespace std;
 
int totalFruits(int n, vector<int> &arr) {
        
        int l = 0;
        int r = 0;
        
        int count = 0;
        
        map<char, int> mp;
        
        while (r < n) {
            
            mp[arr[r]]++;
            
            while(mp.size() > 2) {
                mp[arr[l]]--;
                
                if(mp[arr[l]] == 0) {
                    mp.erase(arr[l]);
                }
                l++;
            }
            
            if (mp.size()<=2) {
                count = max(count, r-l+1);
            }
            r++;
        }
    
        return count;
    }

// Driver code
int main()
{
    int n = 3;
    int K = 2;
    int arr[] = { 1, 2, 1 };
 
    // Function call
    cout << totalFruits(n, arr);
    return 0;
}
