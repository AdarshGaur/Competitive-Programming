class Solution {
    List<List<Integer>> permutations = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        permutations.clear();
        boolean[] taken = new boolean[nums.length];
        backtrack(nums, taken, new ArrayList<Integer>());
        return permutations;
    }

    public void backtrack(int[] nums, boolean[] taken, List<Integer> tempList){
        if(tempList.size() == nums.length){
            permutations.add(new ArrayList<>(tempList));
            return;
        }
        for(int i=0; i<nums.length; i++){
            if(taken[i])
                continue;
            
            taken[i] = true;
            tempList.add(nums[i]);
            backtrack(nums, taken, tempList);
            tempList.remove(tempList.size() -1);
            taken[i] = false;
        }
        return;
    }
}
