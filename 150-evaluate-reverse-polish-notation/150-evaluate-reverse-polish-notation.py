class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for char in tokens:
            
            if char == "+":
                num1 = stack.pop()
                num2 = stack.pop()
                stack.append(num2+num1)

            elif char == "-":
                num1 = stack.pop()
                num2 = stack.pop()
                stack.append(num2-num1)

            elif char == "*":
                num1 = stack.pop()
                num2 = stack.pop()
                stack.append(num2*num1)
                
            elif char == "/":
                num1 = stack.pop()
                num2 = stack.pop()
                stack.append(int(float(num2)/num1)) 

            else:
                stack.append(int(char))

        return stack.pop()
        