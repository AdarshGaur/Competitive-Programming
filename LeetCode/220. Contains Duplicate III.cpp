// Author : @AdarshGaur

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> s;
        for(int i=0; i<nums.size(); i++){
            if(s.size() > indexDiff){
                s.erase(s.lower_bound(nums[i-indexDiff-1]));
            }
            
            auto lower = s.lower_bound(nums[i] - valueDiff);
            auto upper = s.upper_bound(nums[i] + valueDiff);
            if(lower != s.end() and abs(*lower - nums[i]) <= valueDiff) return true;
            if(upper != s.end() and abs(*upper - nums[i]) <= valueDiff) return true;
            
            s.insert(nums[i]);
        }
        return false;
    }
};
