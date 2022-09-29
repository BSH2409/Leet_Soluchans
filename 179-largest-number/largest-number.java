class Solution {
    

public String largestNumber(int[] nums) {
    if (nums == null || nums.length == 0) {
        return "";
    }
    String[] largest = new String[nums.length];
    for (int i = 0; i < nums.length; i++) {
        largest[i] = String.valueOf(nums[i]);
    }
    Arrays.sort(largest, (a, b) -> (b + a).compareTo(a + b));
    
    if (largest[0].equals("0")) {
         return "0";
    }
    StringBuilder res = new StringBuilder();
    for (String str : largest) {
        res.append(str);
    }
    return res.toString();
        
 }
}
