class Solution {
    public int rob(int[] nums) {
        if(nums.length == 1)
            return nums[0];
        return Math.max(robCircle(nums, 1, nums.length-1), robCircle(nums, 0, nums.length-2));
    }

    public int robCircle(int[] nums, int start, int end) {
        int last = 0;
        int behindLast = 0;
        for(int i=start; i<=end; i++){
            int current = Math.max(behindLast + nums[i], last);
            behindLast = last;
            last = current;
        }
        return last;
    }
}

