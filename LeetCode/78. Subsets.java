class Solution {
    List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {
        res.clear();
        // res.add(new ArrayList<Integer>());
        backtrack(nums, new ArrayList<>(), 0);
        return res;
    }

    private void backtrack(int[] nums, List<Integer> tempList, int start){
        res.add(new ArrayList<>(tempList));
        for(int i=start; i<nums.length; i++){
            tempList.add(nums[i]);
            backtrack(nums, tempList, i+1);
            tempList.remove(tempList.size() -1);
        }
        return;
    }
}
