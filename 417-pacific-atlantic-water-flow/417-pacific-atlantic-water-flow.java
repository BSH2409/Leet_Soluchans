class Solution {
    
    boolean[][] pacific;
    boolean[][] atlantic;
    int m,n;
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        m = heights.length; n = heights[0].length;
        pacific  = new boolean[m][n];
        atlantic = new boolean[m][n];
        for(int i=0;i<n;i++) 
        {
            dfs(0,i,heights,pacific);dfs(m-1,i,heights,atlantic);
        }
        for(int i=0;i<m;i++)
        {
            dfs(i,0,heights,pacific);dfs(i,n-1,heights,atlantic);
        }
        return result;
    }
    private void dfs(int i, int j,int[][] heights,boolean[][] visited){
        if(visited[i][j]) return;
        
        visited[i][j]=true;
        
        if(atlantic[i][j] && pacific[i][j]) result.add(Arrays.asList(i,j));
        if(i>0   && heights[i-1][j]>= heights[i][j]) dfs(i-1,j,heights,visited);
        if(j>0   && heights[i][j-1]>= heights[i][j]) dfs(i,j-1,heights,visited);
        if(i<m-1 && heights[i+1][j]>= heights[i][j]) dfs(i+1,j,heights,visited);
        if(j<n-1 && heights[i][j+1]>= heights[i][j]) dfs(i,j+1,heights,visited);
    }
}