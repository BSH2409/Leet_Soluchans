class Solution 
{
    public int eraseOverlapIntervals(int[][] intervals) 
    {
        int n = intervals.length;
        if(n == 1)  return 0;
     
        Arrays.sort(intervals, (a,b) -> a[1] - b[1]);
        
        int res = 0,prev=0;
        
        for(int i = 1; i < n; i++)
        {
        
            if(intervals[i][0] < intervals[prev][1])
                res += 1;
            else 
                prev=i;
        }
        return res;
    }
}