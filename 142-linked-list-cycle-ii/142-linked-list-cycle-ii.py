class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        hash_set = set()
        while head:
            if head in hash_set:
                return head
            hash_set.add(head)
            head = head.next