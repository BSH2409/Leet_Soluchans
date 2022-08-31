class Solution {
public:
    unordered_map<int,bool>m;
    int n;
    unordered_map<int,unordered_map<int,bool>> dp;
    bool help(int i, int k)
    {
        if(i==n) return true;
        if(i>n) return false;
        if(k<1) return false;
        if(m[i]==false) return false;
        if(dp[i].find(k)!=dp[i].end()) return dp[i][k];
        return dp[i][k]=help(i+k-1,k-1)||help(i+k,k)||help(i+k+1,k+1);
        
        
    }
    bool canCross(vector<int>& stones) {
        n=stones.back();
        for(int i:stones) m[i]=true;
        return help(1,1);
        
        
    }
};