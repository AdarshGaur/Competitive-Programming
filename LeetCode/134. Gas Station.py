#Author: @AdarshGaur

class Solution:
    # def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
    #     n = len(gas)
    #     start, end, total = n-1, 0, gas[-1] - cost[-1]
    #     while start > end:
    #         if total >= 0:
    #             total += gas[end] - cost[end]
    #             end += 1
    #         else:
    #             start -= 1
    #             total += gas[start] - cost[start]
    #     return start if total >= 0 else -1
    

    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total, start, curSum = 0, 0, 0
        for i in range(len(gas)):
            total += gas[i] - cost[i]
            curSum += gas[i] - cost[i]
            if curSum < 0:
                start = i+1
                curSum = 0
        return start if total >= 0 else -1

