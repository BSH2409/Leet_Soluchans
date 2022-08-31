class Solution {
public:
    unordered_map<int,int> dp;
    int help(int i, vector<int>&nums)
    {
        if(i<0) return 0;
        if(dp.find(i)!=dp.end()) return dp[i];
        int leave = 0+ help(i-1,nums);
        int take = nums[i] + help(i-2,nums);
        
        return dp[i]=max(leave,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return help(n-1,nums);
    }
};