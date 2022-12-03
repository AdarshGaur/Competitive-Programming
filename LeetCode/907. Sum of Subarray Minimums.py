#Author: @AdarshGaur

class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        arr = [-math.inf] + arr + [-math.inf]
        stack = []
        res = 0
        for i, n in enumerate(arr):
            while stack and arr[stack[-1]] > n:
                mid = stack.pop()
                res += arr[mid] * (mid - stack[-1]) * (i - mid)
            stack.append(i)
        return res % (10**9 +7)
            
