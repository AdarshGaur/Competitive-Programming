#Author: @AdarshGaur

class MyQueue:

    def __init__(self):
        self.fifo = []
        self.lifo = []

    def push(self, x: int) -> None:
        self.fifo.append(x)

    def pop(self) -> int:
        if len(self.lifo) == 0:
            while(len(self.fifo)):
                self.lifo.append(self.fifo.pop())
        return self.lifo.pop()

    def peek(self) -> int:
        if len(self.lifo) == 0:
            while(len(self.fifo)):
                self.lifo.append(self.fifo.pop())
        return self.lifo[-1]

    def empty(self) -> bool:
        return len(self.lifo) == len(self.fifo) == 0

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
