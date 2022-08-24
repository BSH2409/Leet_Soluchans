/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int n=0;
    unordered_map<int,int> count;
    int p=0,l=0,r=0;
    int f;
    int help(TreeNode *root)
    {
        if(!root) return 0;
        if(root->left && root->left->val ==f) p=root->val;
        else if(root->right && root->right->val==f) p=root->val;
        
        if(root->val==f) {
            if(root->left)
                l=root->left->val;
            if(root->right)
                r=root->right->val;
        }
        return count[root->val]=1+ help(root->left) + help(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        f=x;
        help(root);
        
        int parent=0,left,right;
        parent = n - count[x] ; left=count[l] ,right=count[r];
        // cout<<parent<<" "<<left<<" "<<right<<endl;
        if( 2*max({parent,left,right}) > (parent+ left +right)) return true;
                
        return false;
    }
};