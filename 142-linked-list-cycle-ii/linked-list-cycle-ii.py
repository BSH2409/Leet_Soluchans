class Solution(object):
    def detectCycle(self, head):
        
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                while head!=slow:
                    head=head.next
                    slow=slow.next
                return slow
        
        return None