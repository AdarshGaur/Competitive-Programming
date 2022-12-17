#Author: @AdarshGaur

class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        d = [0 for _ in range(10)]
        l1, l2, s = [1, 4, 7, 2, 5, 8], [2, 5, 8, 1, 4 ,7], 0
        for i in digits:
            s += i
            d[i] += 1
        
        while s % 3 != 0:
            for i in l1 if s%3 == 1 else l2:
                if d[i] > 0:
                    d[i] -= 1
                    s -= i
                    break;
        
        ans = ""
        for i in range(9, -1, -1):
            ans += str(i) * d[i]
        
        if len(ans) and ans[0] == '0':
            ans = "0"
        return ans

