#Author: @AdarshGaur

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        def op(v1, v2, c):
            if c == '+': return v1 + v2
            elif c == '-': return v1 - v2
            elif c == '*': return v1 * v2
            else:
                d = v1/v2
                return math.floor(d) if d > 0 else math.ceil(d)

        stack = []
        for c in tokens:
            if c in "+-*/":
                last = stack.pop()
                last2 = stack.pop()
                v = op(last2, last, c)
                stack.append(v)
            else:
                stack.append(int(c))
        return stack[0]

