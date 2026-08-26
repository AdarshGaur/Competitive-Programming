class Solution {
    public int getSum(int a, int b) {
        // if we can't use mathematical operator then we have to use binary operations over it's binary form
        int carryBits = 0;
        while(b != 0){ // important as b could also go negative and we still would need to process that.
            carryBits = (a & b);
            a ^= b;
            b = (carryBits << 1);
        }
        return a;
    }
}
