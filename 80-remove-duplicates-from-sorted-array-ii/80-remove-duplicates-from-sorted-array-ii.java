class Solution {
    public int removeDuplicates(int[] nums) {
        
        Map<Integer,Integer> map=new HashMap<>();
        int cur_index=1;
        map.put(nums[0],1);
        
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[cur_index++]=nums[i];
                map.put(nums[i],1);
            }
            else if(map.get(nums[i])<2)
            {
                nums[cur_index++]=nums[i];
                map.put(nums[i],map.get(nums[i])+1);
            }
        }
        return cur_index;
    }
}