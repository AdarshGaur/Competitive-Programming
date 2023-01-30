#Author: @AdarshGaur

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        ans = []
        last = 0
        for i, s in enumerate(strs):
            new_s = ''.join(sorted(s))
            # print(type(new_s))
            if d.get(new_s) != None:
                ans[d[new_s]].extend([s])
            else:
                ans.append([s])
                d[new_s] = last
                last += 1
        return ans
