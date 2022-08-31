# Author : @AdarshGaur

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        mx = 3 ** 19
        return n > 0 and mx % n == 0
    
#     def isPowerOfThree(self, n: int) -> bool:
#         if n <= 0 :
#             return False
#         elif n == 1 :
#             return True
#         elif n % 3 != 0 :
#             return False
#         return self.isPowerOfThree(n/3)
