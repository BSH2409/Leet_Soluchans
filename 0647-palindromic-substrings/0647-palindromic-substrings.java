class Solution {
    public int countSubstrings(String s) {
        int len= s.length();
        int result = 0;
        int i = 0;
        while (i < len) {
            int start = i++;
            while (i < len && s.charAt(start) == s.charAt(i)) {
                i++;
            }
			
            int centerLen = i - start;
            result += centerLen * (centerLen + 1) / 2;

            result += expandPalindrome(s, start - 1, i);
        }

        return result;
    }

    private int expandPalindrome(String s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
            count++;
        }
        return count;
    }
}