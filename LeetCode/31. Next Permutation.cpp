// Author : Adarsh Gaur

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                int k = nums.size()-1;
                while( k > i){
                    if(nums[k] > nums[i]){
                        swap(nums[i], nums[k]);
                        break;
                    }
                    k--;
                }
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
