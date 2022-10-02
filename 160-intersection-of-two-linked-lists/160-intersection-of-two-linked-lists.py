class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        ptra, ptrb = headA, headB
        while (ptra != ptrb):
            if ptra:
                ptra= ptra.next
            else :
                ptra= headB
                
            if ptrb:
                ptrb= ptrb.next
            else :
                ptrb= headA
                
        return ptra