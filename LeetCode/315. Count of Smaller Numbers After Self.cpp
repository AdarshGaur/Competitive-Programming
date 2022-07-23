// Author : @AdarshGaur

class Solution {
public:
    #define ff first
    #define ss second
    #define iterator vector<pair<int,int>>::iterator
    
    void countMergeSort(iterator& left, iterator& right, vector<int>& count){
        if(right - left <= 1) return;
        iterator mid = left + (right - left)/2;
        // [left, mid)
        countMergeSort(left, mid, count);
        countMergeSort(mid, right, count);
        for(iterator i = left, j = mid; i<mid; i++){
            while(j<right and (*j).ff < (*i).ff ) j++;
            count[(*i).ss] += (j - mid);
        }
        inplace_merge(left, mid, right);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++)
            v.push_back({nums[i], i});
        iterator left = v.begin(), right = v.end();
        countMergeSort(left, right, count);
        return count;
    }
};
