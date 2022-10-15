class Solution(object):
    def maximalSquare(self, matrix):
        
        if not matrix:
            return 0
        
        m, n = len(matrix), len(matrix[0])
        res = 0
        
        dp = [[0] * (n+1) for _ in range(m+1)]
        
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if matrix[i][j] == "1":
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1])
                    res = max(res, dp[i][j])
        return res * res