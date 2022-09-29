class Solution {
    public int majorityElement(int[] nums) {
    Map<Integer, Integer> hash = new HashMap<Integer, Integer>();

    for (int element: nums) {
        if (!hash.containsKey(element))
            hash.put(element, 1);
        else
            hash.put(element, hash.get(element)+1);
        if (hash.get(element)>nums.length/2) {
            return element;
        }
    }
    return 0;
}
}