class Solution {
    public int maxProfit(int[] prices) {
        // we need to maximize the profit for just a single trade only. 
        // in that case we just need to check which could the least price at which 
        // we could've bought the share to sell at (i)th day to make the profit
        // and the maximum profit we could find at any day is our solution
        int minimumBuyPrice = Integer.MAX_VALUE;
        int maxProfit = 0;
        for(int price: prices){
            maxProfit = Math.max(maxProfit, price - minimumBuyPrice);
            minimumBuyPrice = Math.min(minimumBuyPrice, price);
        }
        return maxProfit;
    }
}
