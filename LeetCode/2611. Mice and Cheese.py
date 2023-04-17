#Author: @AdarshGaur

class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        if k == 0: return sum(reward2)
        diff = [i - j for i, j in zip(reward1, reward2)]
        diff = sorted(diff)[-k:]
        return sum(reward2) + sum(diff)
    
