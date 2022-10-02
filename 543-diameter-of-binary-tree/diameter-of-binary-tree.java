public class Solution {
    int res= 0;
    
    public int diameterOfBinaryTree(TreeNode root) {
        help(root);
        return res;
    }
    
    private int help(TreeNode root) {
        if (root == null) return 0;
        
        int left =  help(root.left);
        int right = help(root.right);
        
        res = Math.max(res, left + right);
        
        return 1+ Math.max(left, right);
    }
}