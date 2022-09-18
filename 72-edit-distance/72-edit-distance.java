class Solution {
    
    public int minDistance(String word1, String word2) {
        if (word1 == null || word1.length() == 0) return word2.length();
        if (word2 == null || word2.length() == 0) return word1.length();
        int[][] dp = new int[word1.length()][word2.length()];
        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                dp[i][j] = -1;
            }
        }
        return match(word1, word2, 0, 0,dp);
    }
    
    private int match(String s1, String s2, int i, int j, int[][] dp) {
       
        if (s1.length() == i) {
            return s2.length() - j;
        }
        if (s2.length() == j) {
            return s1.length() - i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int res;
        
        if (s1.charAt(i) == s2.charAt(j)) {
            res = match(s1, s2, i + 1, j + 1,dp);
        } else {
        
            int insert = match(s1, s2, i, j + 1,dp);
        
            int delete = match(s1, s2, i + 1, j,dp);
        
            int replace = match(s1, s2, i + 1, j + 1,dp);
        
            res = Math.min(Math.min(insert, delete), replace) + 1;
        }
        
        return dp[i][j]=res;
    }
}  