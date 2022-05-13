// Author : @AdarshGaur

class NumArray {
public:
    vector<int> pref;
    NumArray(vector<int>& nums) {
        pref.resize(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); i++)
            pref[i] = pref[i-1] + nums[i-1];
    }
    
    int sumRange(int left, int right) {
        return pref[right+1] - pref[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
