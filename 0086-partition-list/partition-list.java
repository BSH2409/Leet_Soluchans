class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode left = null;
        ListNode right = null;
        
        ListNode left_ptr = left;
        ListNode right_ptr = right;
        
        while(head != null){
            if(head.val < x){
                if(left_ptr==null) left_ptr=left=head;
                else 
                {
                    left_ptr.next = head;
                    left_ptr = left_ptr.next;
                }
            }
            else{
                if(right_ptr==null) right_ptr=right=head;
                else 
                { 
                    right_ptr.next = head;
                    right_ptr = right_ptr.next;
                }
            }
            head = head.next;
        }
        
        if(left_ptr !=null) left_ptr.next = right;
        else return right;
        if(right_ptr!=null) right_ptr.next = null;
        
        return left;
    }
}