#Author: @AdarshGaur

class Solution:
    # def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # n = len(temperatures)
        # dp = [n for _ in range(101)]
        # ans = [0 for _ in range(n)]
        # for i in range(n-1, -1, -1):
        #     closest = n
        #     for j in range(temperatures[i]+1, 101):
        #         closest = min(closest, dp[j])
        #     dp[temperatures[i]] = i
        #     if closest != n:
        #         ans[i] = closest - i
        # return ans


    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        stack = []
        ans = [0 for _ in range(n)]
        for i in range(n-1, -1, -1):
            while stack and T[stack[-1]] <= T[i]:
                stack.pop()
            ans[i] = stack[-1] - i if stack else 0
            stack.append(i)
        return ans


