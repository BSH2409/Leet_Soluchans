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
    int mn=INT_MAX,mx=INT_MIN;
    vector<int> hash =vector(200002,0);
    void traverse(TreeNode* root)
    {
        if(!root) return;
        hash[ 1e5 +root->val]++;
        mn=min(mn,root->val);
        mx=max(mx,root->val);
        traverse(root->left),traverse(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        traverse(root1) ; traverse(root2);
        
        vector<int> ans;
        for(int i=mn;i<=mx ;i++)
        {
            if(hash[1e5 + i])
                for(int j=0;j<hash[1e5 + i];j++)
                    ans.push_back(i);
        }
        return ans;
    }
};