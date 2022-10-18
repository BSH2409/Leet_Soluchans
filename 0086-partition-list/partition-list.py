class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        left, right = None,None
        left_ptr,right_ptr= left, right
        while head:
            if head.val < x:
                if left_ptr == None:
                    left_ptr=left=head
                else:
                    left_ptr.next=head
                    left_ptr=left_ptr.next
            else:
                if right_ptr == None:
                    right_ptr=right=head
                else:
                    right_ptr.next=head
                    right_ptr=right_ptr.next
            head=head.next
        if left_ptr != None:
            left_ptr.next=right
        else:
            return right
        
        if right_ptr != None:
            right_ptr.next=None
        return left