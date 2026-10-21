class Solution {
    // public List<Integer> circularPermutation(int n, int start) {
    //     // gray code
    //     List<Integer> grayCodes = new ArrayList<>();
    //     List<Integer> permutation = new ArrayList<>();
    //     int idx = 0;
    //     for(int i=0; i<(1<<n); i++){
    //         int grayCode = (i ^ (i>>1));
    //         grayCodes.add(grayCode);
    //         if(grayCode == start)
    //             idx = i;
    //     }
    //     for(int i=idx; i<(1<<n); i++){
    //         permutation.add(grayCodes.get(i));
    //     }
    //     for(int i=0; i<idx; i++){
    //         permutation.add(grayCodes.get(i));
    //     }
    //     return permutation;
    // }

    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> ans = new ArrayList<>();
        int[] nums = {start};
        backtrack(ans, nums, n-1);
        return ans;
    }

    private void backtrack(List<Integer> ans, int[] nums, int bitPosition){
        if(bitPosition < 0){
            ans.add(nums[0]);
            return;
        }
        backtrack(ans, nums, bitPosition -1);
        nums[0] ^= (1<<bitPosition);
        backtrack(ans, nums, bitPosition -1);
        return;
    }
}
