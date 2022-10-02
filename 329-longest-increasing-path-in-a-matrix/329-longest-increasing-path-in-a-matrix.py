class Solution:

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m,n = len(matrix), len(matrix[0])

        dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        dp = [[0]*n for _ in range(m)]
        def dfs(i, j):
            if dp[i][j]!=0:
                return dp[i][j]
            res=0
            for dx, dy in dirs:
                x, y = i + dx, j + dy
                if x >= 0 and y >=0 and x<m and y<n and matrix[x][y] > matrix[i][j]:
                    res = max(res, dfs(x, y))
            
            dp[i][j]=1+res
            return dp[i][j]
        
        ans=0
        for i in range(m):
            for j in range(n):
                ans = max(ans, dfs(i, j))
        
        return ans