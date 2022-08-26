/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *ans=nullptr,*ptr=nullptr;
    void help(Node* root)
    {
        if(!root) return;
        
        if(!ans) ans=ptr= new Node(root->val);
        else 
        {
            ptr->next = new Node(root->val);
            ptr->next->prev=ptr;
            ptr=ptr->next;
        }
        if(root->child)
            help(root->child);
        help(root->next);
    }
    Node* flatten(Node* head) {
        
        help(head);
        
        return ans;
    }
};