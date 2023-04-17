# Author: @AdarshGaur

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for i in range(len(flowerbed)):
            prv, nxt = max(0, i-1), min(i+1, len(flowerbed)-1)
            if flowerbed[prv] == 0 and flowerbed[nxt] == 0 and flowerbed[i] == 0:
                flowerbed[i] = 1
                n -= 1
        return n <= 0

