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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> crics;
        ListNode* prev= head;
        head = head->next;
        int n=0;
        while(head&&head->next)
        {
                int p= prev->val, cur=head->val,next=head->next->val;
                if(p<cur && cur>next) crics.push_back(n);
                else if( p>cur && cur<next) crics.push_back(n);
                prev= head;head=head->next;n++;
        }
        if(crics.size()<2)
            return {-1,-1};
        int a=INT_MAX,b=INT_MIN;
        for(int i=0;i<crics.size()-1;i++)
            a= min( a, crics[i+1]-crics[i]);
        b= crics.back() - crics[0];
        
        return {a,b};
    }
};