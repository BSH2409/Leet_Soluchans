public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode ptra=headA, ptrb=headB;
        while(ptra!=ptrb){
            if(ptra==null) ptra=headB;
            else  ptra=ptra.next;
            if(ptrb==null) ptrb=headA;
            else ptrb=ptrb.next;
        }
        return ptra;
    }
}