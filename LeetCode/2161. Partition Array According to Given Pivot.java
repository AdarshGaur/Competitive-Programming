class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] res = new int[n];
        int cnt = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                res[j] = nums[i];
                j++;
            } else if (nums[i] == pivot){
                cnt++;
            }
        }
        while(cnt > 0){
            res[j] = pivot;
            j++;
            cnt--;
        }
        for(int i=0; i<n; i++){
            if(nums[i] > pivot){
                res[j] = nums[i];
                j++;
            }
        }
        return res;
    }
}

