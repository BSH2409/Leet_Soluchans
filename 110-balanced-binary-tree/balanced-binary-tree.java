
class Solution {
    public boolean isBalanced(TreeNode root) {
        return height(root)!=-1;
    }
    public int height(TreeNode root){
        if(root==null)
            return 0;
        
        int left_height=height(root.left);
        if(left_height==-1)
            return -1;
        
        int right_height=height(root.right);
        if(right_height==-1)
            return -1;

        if(Math.abs(left_height-right_height)>1)
            return -1;

        return Math.max(left_height,right_height)+1;
    }
}