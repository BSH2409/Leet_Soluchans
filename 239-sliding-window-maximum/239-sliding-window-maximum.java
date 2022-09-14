
    class Solution {
    public int[] maxSlidingWindow(int[] arr, int k) {
        int n = arr.length, j = 0;
        int[] ans = new int[n - k + 1];
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < n; i++) {
            maxHeap.add(new int[]{arr[i], i});
            if (i + 1 >= k)
                
                ans[j++] = maxHeap.peek()[0];
            
            while (maxHeap.size() > 0 && i - maxHeap.peek()[1] + 1 >= k) 
                maxHeap.poll();
        }
        return ans;
    }
}
