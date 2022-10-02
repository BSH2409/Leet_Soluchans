public class Solution {
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
Set visited = new HashSet<>();

    while ( headA != null ) {
        visited.add(headA);
        headA = headA.next;
    }
    
    while ( headB != null ) {
        if ( visited.contains(headB) ) {
            return headB;
        } else {
            headB = headB.next;
        }
    }
    return null;
}
}