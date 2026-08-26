class Solution {
    public int climbStairs(int n) {
        // the number of ways we can reach at nth stair would be 
        // the sum of number of ways we reached at (n-1)th stair and (n-2)th stair
        if(n == 1)
            return 1;
        int last = 2, secondLast = 1;
        for(int i=2; i<n; i++){
            int temp = last;
            last = last + secondLast;
            secondLast = temp;
        }
        return last;
    }
}
