class Solution {
    public int maxProduct(int[] nums) {
        // keep the products of the subarrays in 2 possible ways, 1 for max positive and other for max negative.
        // [][0] will be for negative numbers 
        // [][1] will be for positive numbers 
        int[][] products = new int[nums.length][2];
        products[0][0] = products[0][1] = nums[0];
        int maxProduct = nums[0];
        for(int i=1; i < nums.length; i++){
            if(nums[i] < 0){
                // get the max negative
                products[i][0] = Math.min(nums[i] * products[i-1][1], nums[i]);

                // get the max positive
                products[i][1] = Math.max(nums[i] * products[i-1][0], nums[i]);
            }else{
                // get the max negative
                products[i][0] = Math.min(nums[i] * products[i-1][0], nums[i]);

                // get the max positive
                products[i][1] = Math.max(nums[i] * products[i-1][1], nums[i]);
            }
            maxProduct = Math.max(maxProduct, Math.max(products[i][0], products[i][1]));
        }
        return maxProduct;
    }
}

