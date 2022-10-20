class Solution {
    public List<List<Integer>> combinationSum(int[] cand, int target) {
        List<List<Integer>> ans = new ArrayList<>(); 
        List<Integer> temp = new ArrayList<>();  
        int index = 0; 
        help(index,ans,cand,target,temp); 
        return ans;
    }
    static void help(int index,List<List<Integer>>ans,int arr[],int target,List<Integer> temp) {
       
		if(index == arr.length) {
            if(target == 0) {
                ans.add(new ArrayList<>(temp)); 
            }
            return;
        }
		
		
        if(arr[index] <= target) {
            temp.add(arr[index]);
            help(index,ans,arr,target-arr[index],temp);
            temp.remove(temp.size()-1); 
        }
        help(index+1,ans,arr,target,temp); 
    }
}