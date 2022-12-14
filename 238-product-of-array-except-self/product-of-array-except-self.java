public class Solution {
public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] res = new int[n];
    
    int runningprefix = 1;
    for(int i = 0; i < n; i++){
        res[i] = runningprefix;
        runningprefix*= nums[i];
    }
    int runningsufix = 1;
    for(int i = n -1; i >= 0; i--){
        res[i] *= runningsufix;
        runningsufix *= nums[i];
    }
    return res;
    
}
}