class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int prefix = 1, suffix = 1;
        int[] ans = new int[n];
        Arrays.fill(ans, 1);
        for(int i=0; i<n; i++){
            // keep the prefix
            ans[i] *= prefix;
            prefix *= nums[i];

            // keep the suffix
            ans[n-1 -i] *= suffix;
            suffix *= nums[n-1 -i];
        }
        return ans;
    }
}
