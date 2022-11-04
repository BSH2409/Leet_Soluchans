class Solution:
    def trap(self, height: List[int]) -> int:
        if not height: return 0
        
        n= len(height)
        
        left_max= [height[0]]*n
        right_max=[height[-1]]*n
        
        for i in range(1,n):
            left_max[i]= max(left_max[i-1],height[i])
            right_max[-i-1]= max(right_max[-i],height[-i-1])
            
        ans=0
        
        for i in range(0,n):
            ans+= max(0, (min(left_max[i],right_max[i]) - height[i]))     
        
        
        return ans