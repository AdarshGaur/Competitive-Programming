class Solution {
    List<List<Integer>> permutations = new ArrayList<>();
    int n;

    public List<List<Integer>> permuteUnique(int[] nums) {
        permutations.clear();
        n = nums.length;
        backtrack(nums, new boolean[n], new ArrayList<Integer>());
        return permutations;
    }

    public void backtrack(int[] nums, boolean[] taken, List<Integer> tempList){
        if(tempList.size() == n){
            permutations.add(new ArrayList<>(tempList));
            return;
        }
        HashSet<Integer> alreadyTaken = new HashSet<>();
        for(int i=0; i<n; i++){
            if(taken[i] || alreadyTaken.contains(nums[i]))
                continue;
            
            // taking the same numeric value at sibling level will create duplicates permutations
            alreadyTaken.add(nums[i]);

            taken[i] = true;
            tempList.add(nums[i]);
            backtrack(nums, taken, tempList);
            taken[i] = false;
            tempList.remove(tempList.size() - 1);
        }
        return;
    }
}
