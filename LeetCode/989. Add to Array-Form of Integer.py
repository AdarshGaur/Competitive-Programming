#Author: @AdarshGaur

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        num = num[::-1]
        i = 0
        while k > 0:
            if i == len(num):
                num.append(0)
            num[i] += k%10
            k = k // 10
            k += num[i] // 10
            num[i] = num[i] % 10
            i += 1
        return num[::-1]

