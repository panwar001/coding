#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        
        // If elements are positive then below code works Two pointer solution
       /*
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int sum = 0;
        
        while(right < N) {
            sum = sum + A[right];
            if(sum == K) {
                maxlen = max(maxlen, right-left+1);
            }
            while(sum > K) {
                left = left + 1;
                sum = sum-A[left];
            }
            right++;
        }
        return maxlen;
        */
        // Solution using prefix sum, using hashmap to store prefix sum and index
        // and logic of S[i] = S[i-1] + K
        
        unordered_map<int, int> hashmap;
        int sum = 0;
        int maxlen = 0;
        for(int i = 0; i < N; i++) {
            sum = sum + A[i];
            
            if(sum == K) {
                maxlen = i + 1;
            }
            // If key not found in map iterator  
             // to end is returned 
            else if (hashmap.find(sum-K) != hashmap.end()) {
                maxlen = max(maxlen, i - hashmap[sum-K]);
            }
            
            // if sum is not present in hashmap
            if (hashmap.find(sum) == hashmap.end()) {
                hashmap[sum] = i;
            }
        }
        return maxlen;
    } 

int main() {
    int arr[] = { 10, 5, 2, 7, 1, 9 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 15;
    cout << "Length = " << lenOfLongSubarr(arr, n, k)
         << endl;
  return 0;
}
