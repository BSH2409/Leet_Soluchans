class Solution(object):
    def majorityElement(self, nums):
        count,prev=0,0
        for element in nums :
            if count==0:
                prev=element
            if element==prev :
                count+=1
            else :
                count-=1
        return prev