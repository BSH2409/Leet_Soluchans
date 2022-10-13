class Solution {
    public boolean canJump(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp, -1);
        return help(nums, 0, dp);
    }
    
    public boolean help(int[] nums, int index, int[] dp) {
        if (index >= nums.length-1) 
            return true;
        
        if (nums[index] == 0) {
            dp[index] = 0;
            return false;
        }
        
        if (dp[index] != -1)
            return dp[index]==1;
        

        for (int i = 1; i <= nums[index]; i++) {
            if (help(nums, index+i, dp)) {
                dp[index] = 1;
                return true;
            }
        }
        
        dp[index] = 0;
        return false;
    }
}