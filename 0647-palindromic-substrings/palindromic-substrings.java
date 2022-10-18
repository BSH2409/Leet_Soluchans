class Solution {
    public int countSubstrings(String s) {
        int n= s.length();
        int res= 0;
        int i = 0;
        while (i < n) {
            int start = i++;
            while (i < n && s.charAt(start) == s.charAt(i)) 
                i++;
			
            int repeats = i - start;
            res += repeats * (repeats + 1) / 2;

            res += help(s, start - 1, i);
        }

        return res;
    }

    private int help(String s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
            count++;
        }
        return count;
    }
}