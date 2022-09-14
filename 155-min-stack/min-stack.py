class MinStack:

    def __init__(self):
        self.stack = list()
        self.minstack = list()

    def push(self, x: int) -> None:
        self.stack.append(x)
        if len(self.minstack) == 0 or x <= self.minstack[-1]:
            self.minstack.append(x)

    def pop(self) -> None:
        e = self.stack.pop()
        if e == self.minstack[-1]:
            self.minstack.pop()

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.minstack[-1]