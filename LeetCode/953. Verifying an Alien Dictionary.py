#Author: @AdarshGaur

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        d = {}
        for i, val in enumerate(order):
            d[val] = i
        
        for i in range(1, len(words)):
            n, m = len(words[i-1]), len(words[i])
            ok = False
            for j in range(min(n,m)):
                if ok : break
                if d[ words[i-1][j] ] > d[ words[i][j] ]:
                    return False
                elif words[i-1][j] == words[i][j]:
                    continue
                else:
                    ok = True
            if not ok and n > m:
                return False
        
        return True

