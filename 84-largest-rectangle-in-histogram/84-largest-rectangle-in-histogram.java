class Solution {
    public static int largestRectangleArea(int[] height) {
   
    int[] less_left = new int[height.length]; 
    int[] less_right = new int[height.length];
    less_right[height.length - 1] = height.length;
    less_left[0] = -1;

    for (int i = 1; i < height.length; i++) {
        int prev = i - 1;

        while (prev >= 0 && height[prev] >= height[i]) {
            prev = less_left[prev];
        }
        less_left[i] = prev;
    }

    for (int i = height.length - 2; i >= 0; i--) {
        int next = i + 1;

        while (next < height.length && height[next] >= height[i]) {
            next = less_right[next];
        }
        less_right[i] = next;
    }

    int maxArea = 0;
    for (int i = 0; i < height.length; i++) {
        maxArea = Math.max(maxArea, height[i] * (less_right[i] - less_left[i] - 1));
    }

    return maxArea;
}
}