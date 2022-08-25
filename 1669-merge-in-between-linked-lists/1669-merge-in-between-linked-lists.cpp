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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto temp= list1;
        int i=0;
        while(i<a-1)
            temp=temp->next,i++;
        auto left= temp;
        while(i<=b)
            temp=temp->next,i++;
        auto right=temp;
        
        left->next=list2;
        while(list2 && list2->next)
            list2=list2->next;
        list2->next=right;
        
        return list1;
    }
};