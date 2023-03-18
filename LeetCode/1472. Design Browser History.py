#Author: @AdarshGaur

class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.indx = 0
        

    def visit(self, url: str) -> None:
        while len(self.history) > self.indx +1:
            self.history.pop()
        self.history.append(url)
        self.indx += 1

    def back(self, steps: int) -> str:
        self.indx -= steps
        self.indx = max(self.indx, 0)
        return self.history[self.indx]

    def forward(self, steps: int) -> str:
        self.indx = min(self.indx + steps, len(self.history)-1)
        return self.history[self.indx]



# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)

