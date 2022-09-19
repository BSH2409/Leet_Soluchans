class Solution {
    public List<String> removeInvalidParentheses(String s) {
     int del_left = 0, del_right = 0;
     for (int i = 0; i < s.length(); i++) {
         if (s.charAt(i) == '(') {
             del_left++;
         } else if (s.charAt(i) == ')') {
             if (del_left != 0) {
                 del_left--;
             } else {
                 del_right++;
             }
         }
     }
     Set<String> res = new HashSet<>();
     dfs(s, 0, res, new StringBuilder(), del_left, del_right, 0);
     return new ArrayList<String>(res);
 }
 
 public void dfs(String s, int i, Set<String> res, StringBuilder seq, int del_left, int del_right, int open) {
     if (del_left < 0 || del_right < 0 || open < 0) {
         return;
     }
     if (i == s.length()) {
         if (del_left == 0 && del_right == 0 && open == 0) {
             res.add(seq.toString());
         }        
         return;
     }
 
     char c = s.charAt(i); 
     int len = seq.length();
 
     if (c == '(') {
         dfs(s, i + 1, res, seq, del_left - 1, del_right, open);		    
         dfs(s, i + 1, res, seq.append(c), del_left, del_right, open + 1);      
 
     } else if (c == ')') {
         dfs(s, i + 1, res, seq, del_left, del_right - 1, open);	            
         dfs(s, i + 1, res, seq.append(c), del_left, del_right, open - 1);  	   
 
     } else {
         dfs(s, i + 1, res, seq.append(c), del_left, del_right, open);	
     }
 
     seq.setLength(len);        
 }
 }