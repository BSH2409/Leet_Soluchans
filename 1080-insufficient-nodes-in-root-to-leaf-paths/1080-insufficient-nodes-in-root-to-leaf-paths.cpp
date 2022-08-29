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
    int lim;
    int help(TreeNode* root, int sum=0)
    {
        if(!root) return -1e9;
        sum+=root->val;
        int left =help(root->left,sum);
        int right=help(root->right,sum);
        // cout<<root->val<<" "<<sum+left<<" "<<sum+right<<endl;
        if(root->left && sum+left <lim) root->left=nullptr;
        if(root->right&& sum+right<lim) root->right=nullptr;
        
        if(left==-1e9 && right==-1e9) return root->val;
        return root->val+max(left,right);
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        lim=limit;
        int head=help(root);
        if(head<limit) return nullptr;
        return root;
    }
};