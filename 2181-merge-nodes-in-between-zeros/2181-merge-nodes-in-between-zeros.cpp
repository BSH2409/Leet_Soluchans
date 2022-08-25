/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* ans=nullptr,*ptr=nullptr;
    void help(ListNode * head,int sum=0)
    {
        if(!head) return;
        if(head->val == 0)
        {
            if(ans==nullptr) ptr = ans = new ListNode(sum);
            else ptr->next = new ListNode (sum), ptr=ptr->next;
            sum=0;
        }
        help(head->next,sum+head->val);
    }
    ListNode* mergeNodes(ListNode* head) {
        if(!head ->next) return nullptr;
        help(head->next);
        return ans;
    }
};