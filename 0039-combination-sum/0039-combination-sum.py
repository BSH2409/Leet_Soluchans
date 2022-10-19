class Solution:
    def combinationSum(self, candidates, target):
        ans = []
        # candidates.sort()
        self.help(candidates, target, 0, [],ans)
        return ans
    
    def help(self, nums, target, index, temp, ans):
        if target < 0:
            return
        if target == 0:
            ans.append(temp)
            return 
        for i in range(index, len(nums)):
            self.help(nums, target-nums[i], i, temp+[nums[i]], ans)