#Author: @AdarshGaur

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n, vowels = len(s), 0
        
        def isVowel(c):
            if c in ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'):
                return True
            return False
        
        for i in range(0, n):
            if i < n/2:
                vowels += isVowel(s[i])
            else:
                vowels -= isVowel(s[i])
        return vowels == 0
