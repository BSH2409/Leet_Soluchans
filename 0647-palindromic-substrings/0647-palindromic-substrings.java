class Solution {
    public int countSubstrings(String s) {
        int ans=0;
        dp=new Integer[s.length()][s.length()];
        for(int i=0;i<s.length();i++) {
            for(int j=i;j<s.length();j++) {
                int ret=util(s, i, j);
                ans+=ret;
            }
        }
        return ans;
    }
    Integer dp[][];
    private Integer util(String s, int i, int j) {
        if(i>=j) {
            return 1;
        }
        
        if(dp[i][j]!=null) return dp[i][j];
        
        if(s.charAt(i)==s.charAt(j))
            return util(s, i+1, j-1);
        
        return 0;
            
        }
};