class Solution {
    static bool comp(pair<int, int> itr1, pair<int, int> itr2) {
        return itr1.second > itr2.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int length = nums.size();
        for(int i = 0; i < length; i++) {
            mpp[nums[i]]++;
        }

       // create a vector of pairs and sort that vector using comparator

       vector< pair<int, int> > v(mpp.begin(), mpp.end());

       sort(v.begin(), v.end(), comp);

       vector<int> res;

       for(int i = 0; i < k; i++) {
        res.push_back(v[i].first);
       }
        return res;
    }
};
