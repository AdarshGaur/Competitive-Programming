// Author : @AdarshGaur

class Solution {
public:
    #define iterator vector<int>::iterator
    
    long findPairs(iterator& left, iterator& right){
        if(right - left <= 1) return 0;
        iterator mid = left + (right-left)/2;
        long ans = findPairs(left, mid);
        ans += findPairs(mid, right);
        for(iterator j = mid, i = left; j<right; j++){
            while(i<mid and (*i) <= 2ll * (*j)) i++;
            ans += (mid - i);
        }
        inplace_merge(left, mid, right);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        iterator start = nums.begin(), end = nums.end();
        return findPairs(start, end);
    }
};
