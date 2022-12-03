#Author: @AdarshGaur

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1 = version1.split('.')
        l2 = version2.split('.')
        for i in range(max(len(l1), len(l2))):
            n1 = int(l1[i]) if i < len(l1) else 0
            n2 = int(l2[i]) if i < len(l2) else 0
            if n1 < n2 : return -1
            elif n1 > n2 : return 1
        return 0

