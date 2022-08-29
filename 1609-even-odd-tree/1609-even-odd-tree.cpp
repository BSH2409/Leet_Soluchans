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
    vector<int>last;
    bool help( TreeNode* root, int level=0)
    {
        if(!root) return true;
        if(level+1 > last.size())
        {
            if(level%2==0) last.resize(level+1,INT_MIN);
            else last.resize(level+1,INT_MAX);
        }
        bool left= help(root->left,level+1);
        if(root->val%2 == level%2) return false;
        if(level%2)
            {
                if(root->val< last[level]) last[level]=root->val;
                else return false;
            }
        else
        {
            if(root->val> last[level]) last[level]=root->val;
                else return false;
        }
        bool right=help(root->right,level+1);
        
        return left&&right;
    }
    bool isEvenOddTree(TreeNode* root) {
        return help(root);
    }
};