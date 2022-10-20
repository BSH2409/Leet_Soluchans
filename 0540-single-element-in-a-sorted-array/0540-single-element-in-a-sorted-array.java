class Solution {
    public int singleNonDuplicate(int[] nums) {
        int low=0,high=nums.length-1;
        
        while (low<high)
        {
            int mid = 2*((low+high)/4);
            if(nums[mid]==nums[mid+1])
                low=mid+2;
            else 
                high=mid;
        }
        return nums[low];
    }
}