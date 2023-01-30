#Author: @AdarshGaur

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []

        def backtrack(candidates, curState, indx, target):
            if target == 0:
                ans.append(curState)
                return
            elif target < 0 or indx == len(candidates):
                return
            
            for i in range(indx, len(candidates)):
                if i > indx and candidates[i] == candidates[i-1]: continue
                backtrack(candidates, curState + [candidates[i]], i +1, target - candidates[i])
            
            return ans


        candidates.sort()
        backtrack(candidates, [], 0, target)
        return ans
