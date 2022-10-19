# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        temp = head
        count = 0
        while temp:
            temp = temp.next
            count += 1
        if count <k:
            return head
        n= count//k
        prev,node= ListNode(0),None
        ret=prev
        for i in range(n):   
            node =None
            temp =head            
            for _ in range(k):    
                nxt  = head.next
                head.next = node   
                node =head        
                head =nxt        
            prev.next=node
            temp.next=head  
            prev=temp
            
        return ret.next