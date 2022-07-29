// Author : @AdarshGaur

class Solution {
public:
    
    vector<int> search(vector<int>& A, int l, int r, int& target){
        if(r < l) return {-1, -1};
        if(A[l] == target and A[r] == target) return {l, r};
        if(A[l] <= target and target <= A[r]){
            int m = l + (r-l)/2;
            auto L = search(A, l, m, target);
            auto R = search(A, m+1, r, target);
            if(L[0] == -1) return R;
            if(R[1] == -1) return L;
            return {L[0], R[1]};
        }
        return {-1,-1};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
};
