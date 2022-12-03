#Author: @AdarshGaur

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        a = Counter(word1).values()
        b = Counter(word2).values()
        return Counter(a) == Counter(b) and set(word1) == set(word2)

