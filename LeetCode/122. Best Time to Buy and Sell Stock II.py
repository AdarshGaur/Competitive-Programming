#Author: @AdarshGaur

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        last, profit = prices[0], 0
        for p in prices:
            if p > last:
                profit += p - last
            last = p
        return profit
