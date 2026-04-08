class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        for(int[] q: queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            long v = q[3];

            int idx = l;
            while(idx <= r){
                long val = (nums[idx] * v) % (1000_000_007);
                nums[idx] = (int)val;
                idx += k;
            }
        }

        int xor = 0;
        for(int i: nums){
            xor ^= i;
        }
        return xor;
    }
}

