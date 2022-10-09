# Author : @AdarshGaur

class TimeMap:

    def __init__(self):
        self.dict = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.dict[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        if not key in self.dict:
            return ""
        
        mp = self.dict[key]
        ans = ""
        l, r = 0, len(mp)-1
        while l <= r:
            mid = (l+r)//2
            x = mp[mid]
            if x[1] < timestamp:
                ans = x[0]
                l = mid +1
            elif x[1] > timestamp:
                r = mid-1
            else:
                return x[0]
        return ans


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
