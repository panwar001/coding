#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();

        // using sort and select method TC - onlogn
        /* 
            sort(nums.begin(), nums.end());
            return nums[n-k];
        */

        //using priority queue min heap of size k - Ologk
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();

        // using quick select algorithm - o(N),
    }
};

int main() {
  vector<int> nums = {3,2,1,5,6,4};
  int k = 2;
  Solution obj;
  cout << obj.findKthLargest(nums, k);
  return 0;
}
