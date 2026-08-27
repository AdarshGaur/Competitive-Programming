class Solution {
    public int findMin(int[] nums) {
        int leftIdx = 0, rightIdx = nums.length -1;
        int midIdx = (leftIdx + rightIdx)>>1;
        while(leftIdx < rightIdx){
            if(nums[midIdx] >= nums[rightIdx]){
                leftIdx = midIdx +1;
            }else{
                rightIdx = midIdx;
            }
            midIdx = (leftIdx + rightIdx)/2;
        }
        return nums[leftIdx];
    }
}

