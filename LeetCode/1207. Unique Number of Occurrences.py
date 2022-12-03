#Author: @AdarshGaur

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freq = {}
        for n in arr:
            if n in freq:
                freq[n] += 1
            else:
                freq[n] = 1
        
        cnt = {}
        for f in freq.values():
            if f in cnt:
                return False
            cnt[f] = True
        
        return True
