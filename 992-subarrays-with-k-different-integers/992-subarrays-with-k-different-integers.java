class Solution {
     public int subarraysWithKDistinct(int[] nums, int k) {
        return subarraysWithKSize(nums,k)-subarraysWithKSize(nums,k-1);   
       }
    public int subarraysWithKSize(int[] nums, int k) {
            HashMap<Integer,Integer> hs=new HashMap<>();
            int count=0;
            int n=nums.length;
            int window_start=0;
            int window_end=0;
            while(window_end<n){
                hs.put(nums[window_end],hs.getOrDefault(nums[window_end],0)+1);
            
                while(hs.size()==k+1){
                    hs.put(nums[window_start],hs.get(nums[window_start])-1);
                    if(hs.get(nums[window_start])==0)
                        hs.remove(nums[window_start]);
                    window_start++;
                    
                }
                
                count+=window_end-window_start+1;
                window_end++;

            }
            
            
            return count;
            
        }
}