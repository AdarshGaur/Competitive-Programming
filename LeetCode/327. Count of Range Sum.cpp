// Author : @AdarshGaur

class Solution {
public:
    #define iterator vector<long>::iterator
    
    long findPairs(iterator& left, iterator& right, int& lower, int& upper){
        if(right - left <= 1) return 0;
        iterator mid = left + (right-left)/2;
        long cnt = findPairs(left, mid, lower, upper) + findPairs(mid, right, lower, upper);
        for(iterator i=left, j1 = mid, j2 = mid; i<mid; i++){
            while(j1 < right and (*j1) - (*i) < lower) j1++;
            while(j2 < right and (*j2) - (*i) <= upper) j2++;
            cnt += (j2 - j1);
        }
        inplace_merge(left, mid, right);
        return cnt;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> psum(nums.size()+1, 0ll);
        for(int i=0; i<nums.size(); i++)
            psum[i+1] = psum[i] + nums[i];
        iterator left = psum.begin(), right = psum.end();
        return findPairs(left, right, lower, upper);
    }
};
