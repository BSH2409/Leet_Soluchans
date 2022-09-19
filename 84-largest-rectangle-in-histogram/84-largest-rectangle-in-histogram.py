class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n=len(heights)
        less_left = [-1] * n
        less_right= [n] * n
    
        
        for i in range (1,n):
            prev= i-1
            while prev>=0 and heights[prev] >= heights[i]:
                prev= less_left[prev]
            less_left[i]=prev
        
    
        for i in range(len(heights)-2,-1,-1):
            next =i+1
            while next < n and heights[next] >= heights[i]:
                next= less_right[next]
            less_right[i]=next
                
        
        max_area = 0
        
        for idx,height in enumerate(heights):
            bars = less_right[idx] - less_left[idx] - 1
            area = bars * height
            max_area = max(max_area, area)
        return max_area