class Solution {
    public int removeElement(int[] nums, int val) {
        int moving_ptr = 0;
        for(int i = 0; i<nums.length;i++){
            
          if(val!=nums[i]){
              nums[moving_ptr++] = nums[i];
              
          } 
        }
        return moving_ptr;
    }
}