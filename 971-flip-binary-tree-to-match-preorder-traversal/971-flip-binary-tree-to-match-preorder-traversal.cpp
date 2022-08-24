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
    vector<int> t;
    vector<int> ans;
    bool help(TreeNode* root,int &i)
    {
        if(!root) return true ;
        
        if(t[i++]!=root->val) return false;
        
        auto left = root->left, right=root->right;
        if( left && left->val!= t[i])
        {
            ans.push_back(root->val);
            swap(left,right);
        }
        
        return help(left,i) && help(right,i);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        t=voyage;
        int i=0;
        if(!help(root,i)) return {-1};
        return ans;
    }
};