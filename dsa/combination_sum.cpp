
/* Problem link 
https://www.geeksforgeeks.org/problems/combination-sum-1587115620/
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
*/

// TO-DO, this solution gives TLE, Use DP

#include <bits/stdc++.h>
using namespace std;

// input test case - 
// 4
// 7 2 6 5
// 16 (target sum)

class Solution {
    
    void calcultateCobinationSum(vector<int> &A, int n, int sum, vector<int> &stack, vector<vector<int>> &ans) {
        
       if (n == 0) {
           if (sum == 0) {
               ans.push_back(stack);
           }
            return;
       }
       
       // Pick
       if (A[n-1] <= sum) {
           stack.push_back(A[n-1]);
           calcultateCobinationSum(A, n, sum-A[n-1], stack, ans);
           stack.pop_back();
       }
       
       // not pick
       calcultateCobinationSum(A, n-1, sum, stack, ans);
        
        return;
    }
    
    
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        // Your code here
        int sum = B;
        int n = A.size();
        vector<vector<int>> ans;
        vector<int> stack;       // to store the selected elements
        
        calcultateCobinationSum(A, n, sum, stack, ans);
        
        for(int i =0; i < ans.size(); i++) {
            sort(ans[i].begin(), ans[i].end());
        }

        // sort the combination set and remove duplicates if any
         sort(ans.begin(), ans.end());
         auto last = unique(ans.begin(), ans.end());
         ans.erase(last, ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends
