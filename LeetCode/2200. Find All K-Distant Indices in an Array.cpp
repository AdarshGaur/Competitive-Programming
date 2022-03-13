// Author : AdarshGaur

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> v, ans;
        for(int i=0; i<n; i++){
            if(nums[i] == key){
                v.push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<v.size(); j++){
                if( abs(i-v[j]) <= k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
