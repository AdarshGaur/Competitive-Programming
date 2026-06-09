class Solution {
    public long maxTotalValue(int[] nums, int k) {
        int mx = 0, mn = Integer.MAX_VALUE;
        for(int i: nums){
            mx = Math.max(mx, i);
            mn = Math.min(mn, i);
        }
        return 1L * k * (mx - mn);
    }
}

