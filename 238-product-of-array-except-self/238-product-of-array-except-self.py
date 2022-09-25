class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        res = [1] * n
        
        runningprefix = 1
        for i in range(0, n):
            res[i] *= runningprefix
            runningprefix *= nums[i]
        
        runningsuffix = 1
        for i in range(n-1,-1,-1):
            res[i] *= runningsuffix
            runningsuffix *=nums[i]
        
        return res