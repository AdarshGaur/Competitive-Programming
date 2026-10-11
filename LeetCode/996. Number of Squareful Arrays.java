class Solution {
    int n, perm = 0;
    Map<Integer, Integer> numsMap = new HashMap<>();

    public int numSquarefulPerms(int[] nums) {
        n = nums.length;
        for(int i: nums){
            numsMap.put(i, numsMap.getOrDefault(i, 0) +1);
        }
        for(Map.Entry<Integer, Integer> e: numsMap.entrySet()){
            int u = e.getKey();
            int v = e.getValue();

            numsMap.put(u, v-1);
            backtrack(u, 1);
            numsMap.put(u, v);
        }
        return perm;
    }

    void backtrack(int previous, int cntTaken){
        if(cntTaken == n){
            perm++;
            return;
        }
        for(Map.Entry<Integer, Integer> e: numsMap.entrySet()){
            int cur = e.getKey();
            int cnt = e.getValue();
            if(cnt > 0){
                long sqrt = (long) Math.sqrt(cur + previous);
                if(sqrt * sqrt == (long)(cur + previous)){
                    numsMap.put(cur, cnt-1);
                    backtrack(cur, cntTaken+1);
                    numsMap.put(cur, cnt);
                }
            }
        }
    }
}
