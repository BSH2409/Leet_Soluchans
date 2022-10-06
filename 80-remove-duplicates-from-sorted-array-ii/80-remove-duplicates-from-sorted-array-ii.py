class Solution(object):
    def removeDuplicates(self, nums):
        map = dict()
        cur_index = 1
        map[nums[0]]=1
        
        for i in range(1,len(nums)):
            if nums[i]!=nums[i-1]:
                nums[cur_index]=nums[i]
                cur_index+=1
                map[nums[i]]=1
            elif map[nums[i]]<2:
                nums[cur_index]=nums[i]
                cur_index+=1
                map[nums[i]]+=1
        print(nums)               
        return cur_index