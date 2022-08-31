class Solution {
public:
    int help( int i, vector<int>& nums,vector<int> &dp)
    {
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take= nums[i]+ help(i-2,nums,dp);
        int leave=0+ help(i-1,nums,dp);
        
        return dp[i]=max(take,leave);
    }
    int rob(vector<int>& nums) {
        auto n1 =vector(nums.begin(),nums.end()-1);
        auto n2= vector(nums.begin()+1,nums.end());
        if( nums.size()<2) return nums[0];
        vector<int> dp1(n1.size(),-1),dp2(n2.size(),-1);
        return max(help( n1.size()-1 ,n1,dp1) , help(n2.size()-1,n2,dp2));

    }
};