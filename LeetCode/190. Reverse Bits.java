class Solution {
    public int reverseBits(int n) {
        int reversedBits = 0;
        for(int i=0; i<32; i++){
            reversedBits <<= 1;
            reversedBits |= n&1;
            n >>= 1;
        }
        return reversedBits;
    }
}
