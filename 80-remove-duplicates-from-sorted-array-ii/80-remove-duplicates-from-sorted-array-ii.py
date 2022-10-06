class Solution(object):
    def removeDuplicates(self, nums):
        map = dict()
        cur_index = 1
        cur_count = 1
        
        for i in range(1,len(nums)):
            if nums[i]!=nums[i-1]:
                nums[cur_index]=nums[i]
                cur_index+=1
                cur_count=1
            elif cur_count < 2:
                nums[cur_index]=nums[i]
                cur_index+=1
                cur_count+=1
                
        return cur_index