# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, node: TreeNode, target: TreeNode, k: int) -> List[int]:
        res=[]
        def find(root):
            if not root:
                return False
            if root.val==target.val:
                res.append(root)
                return True
            left = find(root.left)
            if left:
                res.append(root)
                return True
            
            right = find(root.right)
            if right:
                res.append(root)
                return True
            
            return False
        find(node)
        _set = set()
        ans=[]
        def kNodes(root,k):
            if root in _set or not root or k<0:
                return
            if k==0:
                ans.append(root.val)
                return
            kNodes(root.left,k-1)
            kNodes(root.right,k-1)
        for i in res:
            kNodes(i,k)
            _set.add(i)
            k-=1
        return ans
        