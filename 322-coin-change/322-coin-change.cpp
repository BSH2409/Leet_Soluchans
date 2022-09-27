class Solution {
public:
    int help(vector<int>& coins, int index, int target)
    {
        if(target<=0)   return 0;
        if(index<0)     return 1e9;
        
        int leave = help(coins, index -1 , target);
        int take  = 1e9;
        
        if( target>= coins[index]) 
                take = 1 + help(coins, index , target - coins[index]);
        
        return min(take,leave);
    }
    int help(vector<int>& arr,int i,int t,vector<vector<int>> &dp)
        
    {
        if(t<=0) return 0;                              
        if(i<0) return 1e9;
        if(dp[i][t]!=-1) return dp[i][t];
        int notake= help(arr,i-1,t,dp);
        int take=INT_MAX;
        if(t>=arr[i])
        {
            take= 1+ help(arr,i,t-arr[i],dp);
        }
        return dp[i][t]=min(take,notake);
    }
    int coinChange(vector<int>& arr, int amount) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(n,vector(amount+1,0));
        for(int t=0;t<=amount;t++)
        {
            if(t%arr[0]==0) dp[0][t]= t/arr[0];
            else dp[0][t]=1e9;
        }
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notake= help(arr,i-1,t,dp);
                int take=INT_MAX;
                if(t>=arr[i])
                {
                    take= 1+ dp[i][t-arr[i]];
                }
                dp[i][t]=min(take,notake);
            }
        }
        int ans= dp[n-1][amount];
        // int ans=help(arr,n-1,amount,dp);
        return ans==1e9?-1:ans;
    }
};