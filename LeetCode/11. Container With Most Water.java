class Solution {
    public int maxArea(int[] height) {
        int maxWater = 0;
        int leftIndex = 0, rightIndex = height.length -1;
        while(leftIndex < rightIndex){
            if(height[leftIndex] < height[rightIndex]){
                maxWater = Math.max(maxWater, height[leftIndex++] * (rightIndex - leftIndex +1));
            }else{
                maxWater = Math.max(maxWater, height[rightIndex--] * (rightIndex - leftIndex +1));
            }
        }
        return maxWater;
    }
}

