// Author : Adarsh Gaur

class Solution {
public:
    vector<int> dif(vector<int>& a, vector<int>& b){
        set<int> s;
        for(auto i: a) s.insert(i);
        for(auto i: b) s.erase(i);
        return vector<int>(s.begin(), s.end());
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {dif(nums1, nums2), dif(nums2, nums1)};
    }
};
