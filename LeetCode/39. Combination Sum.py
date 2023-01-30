#Author: @AdarshGaur

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        self.backtrack(candidates, ans, target, 0)
        return ans
    
    def backtrack(self, A, ans, need, indx, path=[]):
        if need == 0:
            ans.append(path)
            return
        elif need < 0 or indx == len(A):
            return 
        
        for i in range(indx, len(A)):
            self.backtrack(A, ans, need - A[i], i, path + [A[i]])
        return
