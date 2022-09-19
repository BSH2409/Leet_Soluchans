class Solution(object):
    def removeInvalidParentheses(self, s):
        seen = set() # set of states seen (strings)
        ans = []

        q = deque([s])

        while q:
            n = len(q)
            found = False
            for i in range(n):
                node = q.pop()

                if node in seen:
                    continue

                seen.add(node)

                if valid(node):
                    ans.append(node)
                    found = True
                    continue

                for j in range(len(node)):
                    if node[j] == "(" or node[j] == ")":
                        prefix, suffix = node[:j], node[j+1:]
                        newnode = prefix+suffix
                        if newnode not in seen:
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
        