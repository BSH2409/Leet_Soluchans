class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[][] dp=new int[n][n+1];
        for(int[] row: dp) Arrays.fill(row,-1);
        return help(0,nums,-1,dp);
    }
    public static int help(int index,int[] nums,int prev, int [][] dp){
        if(index == nums.length) return 0;
        if(dp[index][prev+1]!=-1)
            return dp[index][prev+1];
        int leave = 0 + help( index+1 , nums , prev ,dp );
        int take  =  0 ;
        if(prev == -1 || nums[index] > nums[prev]){
            take += 1 + help( index+1 , nums , index ,dp );
        }
        return dp[index][prev+1]=Math.max(leave,take);
    }
}