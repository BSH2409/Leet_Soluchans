class Solution(object):
    def removeInvalidParentheses(self, s):
        visited = set() 
        ans = []

        q = deque([s])

        while q:
            n = len(q)
            found = False
            for i in range(n):
                node = q.pop()

                if node in visited:
                    continue

                visited.add(node)

                if valid(node):
                    ans.append(node)
                    found = True
                    continue

                for j in range(len(node)):
                    if node[j] == "(" or node[j] == ")":
                        newnode = node[:j] + node[j+1:]
                        if newnode not in visited:
                            q.appendleft(newnode)
            if found:
                break
        return ans
            
def valid(s):
    open,close = 0,0
    
    for i in range(len(s)):
        if s[i] == "(":
            open+=1
        elif s[i] == ")":
            if open > 0:
                open-=1
            else:
                close+=1
    return open == 0 and close == 0
        