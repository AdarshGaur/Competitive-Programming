class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int INF = 1_000_000;
        int n = arr.length;
        int[] prefixSum = new int[n];
        int[] suffixSum = new int[n];
        

        int prev = 0, tempSum = arr[0];
        prefixSum[0] = INF;
        for(int i=1; i<n; i++){
            while(prev < i && tempSum > target){
                tempSum -= arr[prev];
                prev++;
            }
            if(tempSum == target){
                prefixSum[i] = Math.min(prefixSum[i-1], i - prev);
            }else{
                prefixSum[i] = Math.min(prefixSum[i-1], INF);
            }
            tempSum += arr[i];
        }

        prev = n-1;
        tempSum = arr[n-1];
        suffixSum[n-1] = tempSum == target ? 1 : INF;
        for(int i=n-2; i>=0; i--){
            tempSum += arr[i];
            while(prev > i && tempSum > target){
                tempSum -= arr[prev];
                prev--;
            }
            if(tempSum == target){
                suffixSum[i] = Math.min(suffixSum[i+1], prev - i +1);
            }else{
                suffixSum[i] = Math.min(suffixSum[i+1], INF);
            }
        }

        int result = INF;
        for(int i=0; i<n; i++){
            result = Math.min(result, prefixSum[i] + suffixSum[i]);
        }
        return result == INF ? -1 : result;
    }
}

