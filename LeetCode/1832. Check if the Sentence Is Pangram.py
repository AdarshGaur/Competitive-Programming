# Author : @AdarshGaur

# class Solution:
#     def checkIfPangram(self, s: str) -> bool:
#         if len(s) < 26: return False
#         f = [0 for _ in range(26)]
#         for ch in s:
#             f[ ord(ch) - ord('a') ] += 1
        
#         for i in f:
#             if i == 0:
#                 return False
#         return True

class Solution:
    def checkIfPangram(self, sentence:str) -> bool:
        present = set(sentence)
        return len(present) == 26
