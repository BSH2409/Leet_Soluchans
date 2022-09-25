class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = [x for x in list(str(num))]
        n= len(digits)
        right_bound = [None] * n
        max_index = n-1
        right_bound[max_index] = max_index
        
        for i in range(n-2, -1, -1):
            if digits[i] > digits[max_index]:
                max_index = i
            right_bound[i] = max_index
                

        for i in range(n):
            if digits[i] != digits[right_bound[i]]:
                digits[i], digits[right_bound[i]] = digits[right_bound[i]], digits[i]
                return int(''.join([d for d in digits]))
        
        return num