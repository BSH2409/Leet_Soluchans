class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        if not heights:
            return 0
        stack = []
        maxArea = 0
        i = 0
        while i<= len(heights):
            h=0
            if i!= len(heights):
                h=heights[i]
            if (not stack) or h >= heights[stack[-1]]:
                stack.append(i)
                i += 1 
            else: 
                curHeight = heights[stack.pop()]
                right_min= i-1
                left_min=0
                if (stack):
                    left_min = stack[-1] + 1
                width = right_min - left_min +1
                
                maxArea = max(maxArea, (curHeight*width))
        
        return maxArea
    