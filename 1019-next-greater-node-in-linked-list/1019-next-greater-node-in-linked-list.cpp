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
    class lesser{
        public:
        bool operator()(pair<int,int> &a, pair<int,int> &b)
        {
            return a.first>b.first;
        }
    };
    vector<int> nextLargerNodes(ListNode* head) {
        auto temp=head;
        int i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,lesser> q;
        vector<int> ans;
        while(head)
        {
            int val= head->val;

            if( q.empty() || q.top().first >= val)
                q.push(make_pair(val,i));
            else
            {
                while(!q.empty() && q.top().first<val)
                {
                    int index= q.top().second;
                    q.pop();
                    ans[index]=val;
                }
                q.push(make_pair(val,i));
            }
            head=head->next; i++;
            ans.resize(i+1);
        }
        ans.resize(i);
        return ans;
            
        
    }
};