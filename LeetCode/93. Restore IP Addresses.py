#Author: @AdarshGaur

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []

        def backtrack(cur, ips=[]):
            if len(ips) == 4 and cur == len(s):
                ans.append('.'.join(ips))
                return
            elif len(ips) >= 4 or cur >= len(s):
                return
            for i in range(1, 4):
                ip = s[cur:cur+i]
                if len(ip) > 1 and (ip[0] == '0' or int(ip) > 255):
                    continue
                ips.append(ip)
                backtrack(cur+i, ips)
                ips.pop()

        backtrack(0)
        return ans
