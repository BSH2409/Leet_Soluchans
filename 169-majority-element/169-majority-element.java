class Solution {
    public int majorityElement(int[] nums) {
    int count=0, prev = 0;
    for (int element: nums) {
        if (count==0)
            prev=element;
        if (element!=prev)
            count--;
        else
            count++;
    }
    return prev;
}
}