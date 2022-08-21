// Author : @AdarshGaur

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(), m = haystack.size();
        for(int i=0; i <= m-n; i++){
            int j = 0;
            while(j < n and needle[j] == haystack[i+j])
                j++;
            if(j == n) return i;
        }
        return -1;
    }
};
