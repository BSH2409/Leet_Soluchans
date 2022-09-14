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
    vector<int> levels= vector(1,0);
    void help(TreeNode* root, int level=0)
    {
        if(!root) return;
        if( level >= levels.size()) levels.resize(level+1,0);
        levels[level]+=root->val;
        help(root->left,level+1);
        help(root->right,level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        help(root);
        return levels.back();
    }
};