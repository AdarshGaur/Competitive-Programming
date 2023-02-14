# Author: @AdarshGaur

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = ""
        a, b = a[::-1], b[::-1]
        carry, n, m = 0, len(a), len(b)
        for i in range(max(n,m)):
            cur = carry
            carry = 0
            if i < n and a[i] == '1': cur += 1
            if i < m and b[i] == '1': cur += 1
            if cur > 1: carry = 1
            if cur & 1: ans += "1"
            else: ans += "0"
        if carry:
            ans += "1"
        return ans[::-1]

