// Author : @AdarshGaur

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans = 0;
        set<vector<int>> s;
        for(int i=0; i<nums.size(); i++){
            for(int j=i, d=0; j<nums.size(); j++){
                if(nums[j]%p == 0) d++;
                if(d > k) break;
                s.insert(vector<int>(nums.begin()+i, nums.begin()+j+1));
            }
        }
        return s.size();
    }
};
