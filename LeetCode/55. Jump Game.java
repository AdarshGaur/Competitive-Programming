class Solution {
    public boolean canJump(int[] nums) {
        int canJump = nums[0];
        for(int i=1; i<nums.length; i++){
            if(canJump <= 0)
                return false;
            canJump--;
            canJump = nums[i] > canJump ? nums[i] : canJump; 
        }
        return true;
    }
}

