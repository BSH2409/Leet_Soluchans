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
    int v;
    unordered_map<TreeNode*,bool> visited;
    void help(TreeNode *root, TreeNode* parent, int depth)
    {
        if(visited[parent]) return;
        if(depth!=1 && !root) return;
        if(depth==1)
        {
            TreeNode* left=new TreeNode(v,parent->left,nullptr);
            TreeNode* right=new TreeNode(v,nullptr,parent->right);
            parent->left=left;
            parent->right=right;
            visited[parent]=true;
            return;
        }
        help(root->left,root,depth-1);
        help(root->right,root,depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) return new TreeNode(val,root,nullptr);
        v=val;
        help(root,nullptr,depth);
        return root;
    }
};