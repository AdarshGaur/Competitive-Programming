class Solution {
    List<List<Integer>> subsets = new ArrayList<>();

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        subsets.clear();
        backtrack(nums, new ArrayList<Integer>(), 0);
        return subsets;
    }

    private void backtrack(int[] nums, List<Integer> tempList, int start){
        subsets.add(new ArrayList(tempList));
        for(int i=start; i <nums.length; i++){
            if(i != start && nums[i] == nums[i-1])
                continue;
            tempList.add(nums[i]);
            backtrack(nums, tempList, i+1);
            tempList.remove(tempList.size() -1);
        }
        return;
    }
}
