class Solution {
public:
    int m,n;
    int help(int i, int j,vector<vector<int>> &dp)
    {
        if( i<0 || j<0 || i>=m || j>=n) return 0;
        
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down= help(i+1,j,dp);
        int right= help(i,j+1,dp);
        
        return dp[i][j]=down+right;
    }
    int uniquePaths(int mm, int nn) {
        m=mm,n=nn;
        vector<vector<int>> dp(m+1,vector(n+1,-1));
        return help(0,0,dp);
    }
};