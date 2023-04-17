#Author: @AdarshGaur

class Solution:
    def removeStars(self, s: str) -> str:
        res = []
        for ch in s:
            if ch == '*':
                res.pop()
            else:
                res += [ch]
        return ''.join(res)

