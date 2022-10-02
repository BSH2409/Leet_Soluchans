class Solution(object):
    def isBalanced(self, root):
        return (self.height(root) !=-1)
    
    def height(self, root):
        if root is None:  
            return 0
        left_height = self.height(root.left)
        if left_height==-1:
            return -1

        right_height= self.height(root.right)
        if right_height==-1:
            return -1
        
        if abs(left_height - right_height) > 1:
            return -1
        
        return 1+ max(left_height, right_height)