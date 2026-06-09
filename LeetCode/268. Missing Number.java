class Solution {
    public int missingNumber(int[] nums) {
        int xor = nums.length;
        for(int i=0; i<nums.length; i++){
            xor ^= i;
            xor ^= nums[i];
        }
        return xor;
    }

//     public int missingNumber(int[] nums) {
//         long sum = 0L;
//         for(int val: nums){
//             sum = sum + val;
//         }
//         int len = nums.length;
//         return (int)(((len * (len + 1L)) >> 1) - sum);
//     }
}

