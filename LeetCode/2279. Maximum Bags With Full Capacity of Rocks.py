#Author: @AdarshGaur

class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        need = [cap - rock for cap, rock in zip(capacity, rocks)]
        need = sorted(need)
        for i in range(1, len(need)):
            need[i] += need[i-1]
        return bisect.bisect(need, additionalRocks)
