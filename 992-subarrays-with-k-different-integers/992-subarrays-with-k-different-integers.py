class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        
        def helper(nums, k):
            window_start = 0
            window_end = 0
            count = 0
            hash_set = set()
            hash_map = collections.Counter()

            while window_end < len(nums):
                hash_set.add(nums[window_end])
                hash_map[nums[window_end]] += 1

                while len(hash_set) == k+1:
                    hash_map[nums[window_start]] -= 1
                    if hash_map[nums[window_start]] == 0:
                        hash_set.remove(nums[window_start])
                    window_start += 1

                count += (window_end - window_start + 1)

                window_end += 1
            return count
    
        return helper(nums, k) - helper(nums, k - 1)