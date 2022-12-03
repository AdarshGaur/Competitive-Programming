#Author: @AdarshGaur

class Solution:
    def frequencySort(self, s: str) -> str:
        d = Counter(s)
        bucket = [ "" for _ in range(len(s)+1)]
        for c, freq in d.items():
            bucket[freq] += (c * freq)
        
        ans = ""
        for i in range(len(s), 0, -1):
            if bucket[i]:
                ans += bucket[i]
        return ans
