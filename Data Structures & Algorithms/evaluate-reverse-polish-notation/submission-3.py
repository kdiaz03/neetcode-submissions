class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        res = 0

        for t in tokens:
            if t == "+":
                res = stack.pop() + stack.pop()
                stack.append(res)
                continue
            if t == "-":
                res = stack.pop(-2) - stack.pop()
                stack.append(res)
                continue
            if t == "*":
                res = stack.pop() * stack.pop()
                stack.append(res)
                continue
            if t == "/":
                res = int(stack.pop(-2) / stack.pop())
                stack.append(res)
                continue
            else:
                stack.append(int(t))

        return stack.pop()
            
            