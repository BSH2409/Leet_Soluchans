class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start=0, end=0;
        int length=0, max_length=0;
        HashSet<Character> hm= new HashSet<Character>();
        while(start<s.length() && end<s.length()){
            if(!hm.contains(s.charAt(end))){
                hm.add(s.charAt(end));
                end++;
                length= hm.size();
                max_length= Math.max(max_length,length);
            }
            else{
                hm.remove(s.charAt(start));
                start++;
            }
        }
        return max_length;
    }
}