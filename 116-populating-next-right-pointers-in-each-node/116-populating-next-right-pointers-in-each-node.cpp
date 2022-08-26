/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*> p;
    void help(Node* root,int level){
        if(root==NULL) return;
        
        if(p.size()<level+1) p.resize(level+1,NULL);
        
        help(root->right,level+1);
        root->next=p[level];
        p[level]=root;
        help(root->left,level+1);
        
    }
    Node* connect(Node* root) {
        help(root,0);
        return root;
    }
};