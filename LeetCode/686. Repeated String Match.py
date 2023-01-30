#Author: @AdarshGaur

class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        times = (len(b) + len(a) -1 )//len(a)
        for i in range(2):
            if b in a * (times+i):
                return times+i
        return -1

