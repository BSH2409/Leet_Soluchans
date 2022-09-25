class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        import functools
        def comparator(s1, s2):
            if s1+s2 < s2+s1:
                return -1
            if s1+s2 > s2+s1:
                return 1
            return 0
        
        nums = [str(num) for num in nums]
        nums = sorted(nums, key = functools.cmp_to_key(comparator),  reverse = True)
        res = '0' if nums[0] == '0' else ''.join(nums)      
        return res
        