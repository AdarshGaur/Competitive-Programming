#Author: @AdarshGaur

class Solution:
    def countTexts(self, s: str) -> int:
        cache = [0 for _ in range(len(s)+1)]
        cache[0] = 1
        for i in range(0, len(s)):
            cache[i+1] = cache[i]
            if i > 0 and s[i] == s[i-1]:
                cache[i+1] += cache[i-1]
                if i > 1 and s[i] == s[i-2]:
                    cache[i+1] += cache[i-2]
                    if i > 2 and s[i] == s[i-3] and (s[i] == '7' or s[i] == '9'):
                        cache[i+1] += cache[i-3]
            cache[i+1] %= (10**9 +7)
        return cache[-1]

