class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // Subsets
        // print all subsets.

            vector<vector<int>> allCombinations;
            vector<int> emptyCombination;
            allCombinations.push_back(emptyCombination);
    
		    int length = nums.size();
    
		    // calculate total number of combinations
		    int totalCount = pow(2,length);
    
		    // loop over all numbers and checking bit set
		    // logic here is to check the set bits of numbers till 2n
		    for (int count = 1; count < totalCount; count++) {
		       vector<int> combinations;
		        for (int j = 0; j < length; j++) {
		            if ( (count & (1<<j)) != 0) {
		                combinations.push_back(nums[j]) ;
		            }
		        }
		        allCombinations.push_back(combinations);
		    }
		    
		    return allCombinations;
		
    }
};
