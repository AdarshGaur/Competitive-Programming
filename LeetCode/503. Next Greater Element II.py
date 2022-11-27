#Author: @AdarshGaur

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        j, mx = 0, -10**9
        for i, v in enumerate(nums):
            if v > mx:
                j , mx = i, v
        stack = []
        ans = [0] * n
        for i in range(0, n):
            while len(stack) > 0 and stack[-1] <= nums[j]:
                stack.pop()
            if len(stack) == 0:
                ans[j] = -1
            else:
                ans[j] = stack[-1]
            stack.append(nums[j])
            j = (j - 1 + n) % n
        return ans
