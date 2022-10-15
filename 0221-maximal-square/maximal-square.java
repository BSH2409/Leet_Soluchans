class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix.length==0) return 0;
        int res=0;
        int m=matrix.length; int n= matrix[0].length;
        int [][]dp=new int[m+1][n+1];
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1+Math.min(Math.min(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1]);
                    res=Math.max(res,dp[i][j]);
                }
            }
        }
        return res*res;   
    }
};