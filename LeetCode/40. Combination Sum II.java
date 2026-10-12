class Solution {
    List<List<Integer>> validCombinations = new ArrayList<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        validCombinations.clear();
        backtrack(candidates, new ArrayList<Integer>(), target, 0);
        return validCombinations;
    }

    public void backtrack(int[] candidates, List<Integer> combination, int target, int startIdx){
        if(target < 0){
            return;
        }else if(target == 0){
            validCombinations.add(new ArrayList<>(combination));
            return;
        }
        for(int i=startIdx; i<candidates.length; i++){            
            if(i > startIdx && candidates[i] == candidates[i-1])
                continue;
            
            if(candidates[i] > target)
                break;
            
            combination.add(candidates[i]);
            backtrack(candidates, combination, target - candidates[i], i+1);
            combination.remove(combination.size() -1);
        }
        return;
    }

}
