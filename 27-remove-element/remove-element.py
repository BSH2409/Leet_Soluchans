class Solution(object):
    def removeElement(self, nums, val):
        moving_ptr = 0
        for num in nums:
            if num != val:
                nums[moving_ptr] = num
                moving_ptr += 1
        return moving_ptr