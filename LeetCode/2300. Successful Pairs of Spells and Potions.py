#Author: @AdarshGaur

import bisect
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions = sorted(potions)
        ans = []
        for spell in spells:
            x = bisect.bisect_left(potions, (success + spell -1)//spell, 0, len(potions))
            ans.append(len(potions) - x)
        return ans



