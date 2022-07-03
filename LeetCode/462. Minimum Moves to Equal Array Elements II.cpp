// Author: @AdarshGaur

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), moves = 0;
        sort(nums.begin(), nums.end());
        int mid = n/2;
        for(int i=0; i<n; i++){
            moves += abs(nums[i] - nums[mid]);
        }
        return moves;
    }
};
