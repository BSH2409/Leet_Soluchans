class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        res=0
        def height(root):
            nonlocal res
            if not root:
                return 0
            
            left = height(root.left)
            right = height(root.right)
            res = max(res, left + right)
            return 1+max(left, right)
        
        height(root)
        return res