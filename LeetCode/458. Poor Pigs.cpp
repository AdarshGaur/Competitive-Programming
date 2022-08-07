// Author : @AdarshGaur

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int days = minutesToTest/minutesToDie +1;
        double a = log10(buckets);
        double b = log10(days);
        return ceil(a/b);
    }
};
