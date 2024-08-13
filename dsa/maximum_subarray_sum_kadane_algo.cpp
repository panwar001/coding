#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int maxsum = INT_MIN;
    int start_index = 0;
    int end_index = 0;
    for(int i = 0; i < n; i++) {
        // philospohy is if sum becomes negative make it 0, 
        // Adding negative will decrease overall sum
        sum = sum + nums[i];
        //maxsum = max(sum, maxsum);
         if(sum > maxsum) {
            maxsum = sum;
            end_index = i;
        }
        if(sum < 0) {
            sum = 0;
            // starting index for printing, when sum is 0
            start_index = i+1;
        }
    }
    cout << start_index << " , " << end_index << endl;
    return maxsum;
}

int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << "Subarray Sum = " << maxSubArray(nums) << endl;
  return 0;
}
