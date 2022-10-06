class Solution {
    public int removeDuplicates(int[] nums) {
    
        int cur_index=1, cur_count=1;
        
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[cur_index++]=nums[i];
                cur_count=1;
            }
            else if(cur_count<2)
            {
                nums[cur_index++]=nums[i];
                cur_count++;
            }
        }
        return cur_index;
    }
}