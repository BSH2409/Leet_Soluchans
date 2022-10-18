# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:     
        cur,temp,prev = head,head,None
        for _ in range(k):
            if not temp:
                return head
            temp = temp.next
        for _ in range(k):
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        head.next = self.reverseKGroup(cur, k)
        return prev