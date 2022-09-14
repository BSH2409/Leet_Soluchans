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
    bool check(vector<int> &count)
    {
        int odd=0;
        for(auto i:count)
        {   if (i%2!=0)
                odd++;
            if (odd>1) return false;}
        return true;
    }
    int ans=0;
    vector<int> count=vector(10,0);
    void help(TreeNode* root)
    {
        if(!root) return;
        count[root->val]++;
        if( !root->left && !root->right) ans+=check(count);
        help(root->left);
        help(root->right);
        count[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        help(root);
        return ans;
    }
};