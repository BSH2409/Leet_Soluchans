class Solution {
    public int maximumSwap(int num) {
        char[] digits = String.valueOf(num).toCharArray();
        int n=digits.length;
        int[] right_bound = new int[n];
        int max_index = n - 1;
        right_bound[max_index] = max_index;
        
        for (int i = n - 2; i >= 0; i--) {
            if (digits[i] > digits[max_index]) {
                max_index = i;
            }
            right_bound[i] = max_index;
        }
        
        for (int i = 0; i < digits.length; i++) {
            if (digits[i] != digits[right_bound[i]]) {
                char tmp = digits[i];
                digits[i] = digits[right_bound[i]];
                digits[right_bound[i]] = tmp;
                return Integer.parseInt(String.valueOf(digits));
            }
        }
        
        return num;
    }
}