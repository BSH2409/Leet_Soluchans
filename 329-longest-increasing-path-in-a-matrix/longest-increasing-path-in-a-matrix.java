class Solution {
    int[][] dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    // {1,0}=>down, {-1,0}=>up, {0,1}=>right, {0,-1}=>left
    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int ans=0;
        int[][] dp= new int[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int path = dfs(matrix, m, n, i, j, dp);
                ans = Math.max(path, ans);
            }
        }
        
        return ans;
    }
    
    public int dfs(int[][] matrix, int m, int n, int i, int j, int[][] dp) {
        if (dp[i][j]!=0)
            return dp[i][j];
        int res = 0;
        for(int[] d : dir) {
            int x = i+d[0], y = j+d[1]; 
            if(x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] > matrix[i][j]) {
                res = Math.max(res,dfs(matrix, m, n, x, y,dp));
            }
        }
        dp[i][j]= 1+res;
        return dp[i][j];
    }
}