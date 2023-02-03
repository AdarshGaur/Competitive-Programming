#Author: @AdarshGaur

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        bestsell, bestbuy = 0, -prices[0]
        for i in range(1, len(prices)):
            bestsell = max(bestsell, bestbuy + prices[i] - fee)
            bestbuy = max(bestbuy, bestsell - prices[i])
        return bestsell

