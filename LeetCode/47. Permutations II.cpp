// Author : Adarsh Gaur

class Solution {
public:
    bool nextPermutation(vector<int> &a){
        int n = a.size();
        for(int i = n-2; i>=0; i--){
            if(a[i] < a[i+1]){
                int k = n-1;
                while(k > i){
                    if(a[k] > a[i]){
                        swap(a[i], a[k]);
                        break;
                    }
                    k--;
                }
                sort(a.begin()+i+1, a.end());
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while(nextPermutation(nums)){
            ans.push_back(nums);
        }
        return ans;
    }
};
