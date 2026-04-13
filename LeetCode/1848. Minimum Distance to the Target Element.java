class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int left = start;
        int right = start;
        while(left >= 0 && right < nums.length){
            if(nums[left] == target)
                return start - left;
            if(nums[right] == target)
                return right - start;
            left--;
            right++;
        }
        while(left >= 0){
            if(nums[left] == target)
                return start - left;
            left--;
        }
        while(right < nums.length){
            if(nums[right] == target)
                return right - start;
            right++;
        }
        return -1;
    }
}

