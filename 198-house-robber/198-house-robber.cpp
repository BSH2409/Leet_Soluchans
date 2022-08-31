class Solution {
public:
//     unordered_map<int,int> dp;
//     int help(int i, vector<int>&nums)
//     {
//         if(i<0) return 0;
//         if(dp.find(i)!=dp.end()) return dp[i];
//         int leave = 0+ help(i-1,nums);
//         int take = nums[i] + help(i-2,nums);
        
//         return dp[i]=max(leave,take);
//     }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i=2;i<n;i++)
        {
            int leave= 0+ dp[i-1];
            int take= nums[i]+dp[i-2];
            dp[i]=max(leave,take);
        }
        
        return dp[n-1];

    }
};