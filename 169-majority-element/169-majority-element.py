class Solution(object):
    def majorityElement(self, nums):
        hash = {}
        for element in nums:
            hash[element] = hash.get(element, 0) + 1
            if hash[element] > len(nums)//2:
                return element