#Author: @AdarshGaur

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ans = []
        carry = 1
        for i in range(len(digits)-1, -1, -1):
            x = (digits[i] + carry)
            ans.append( x % 10)
            carry = x // 10
        if carry:
            ans.append(carry)
        return ans[::-1]

