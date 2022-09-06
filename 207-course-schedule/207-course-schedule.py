class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        if not prerequisites:
            return True
        
        def dfs(node):
            if visited[node] == 1:
                return False
            visited[node] = 1
            for i in adj[node]:
                if visited[i] != 2 and not dfs(i):
                    return False
            visited[node] = 2
            return True
        adj = collections.defaultdict(list)
        for a,b in prerequisites:
            adj[b].append(a)
            adj[a] 
        visited = [0] * numCourses
        for node in adj:
            if not visited[node]:
                if not dfs(node):
                    return False
        return True
        