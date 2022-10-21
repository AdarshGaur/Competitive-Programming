# Author : @AdarshGaur

class Solution:
    def breakPalindrome(self, s: str) -> str:
        pos , n = -1, len(s);
        if n == 1: return ""
        for i in range(n//2):
            if s[i] != 'a':
                x = s[i]
                return s.replace(x, 'a', 1)
        return s[:-1] + "b"
