class Solution {
public:
    vector<vector<bool>> a;
    vector<vector<bool>> p;
    int m,n;
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &h ,vector<vector<bool>> &visited,int i,int j)
    {
        if(visited[i][j]) return;
        
        visited[i][j]=true;
        
        if(a[i][j] && p[i][j]) ans.push_back({i,j});
        
        if(i>0   && h[i-1][j]>= h[i][j]) dfs(h,visited,i-1,j);
        if(j>0   && h[i][j-1]>= h[i][j]) dfs(h,visited,i,j-1);
        if(i<m-1 && h[i+1][j]>= h[i][j]) dfs(h,visited,i+1,j);
        if(j<n-1 && h[i][j+1]>= h[i][j]) dfs(h,visited,i,j+1);
    }
   
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m=h.size(),n=h[0].size();
        a=p=vector(m,vector(n,false));
        for(int i=0;i<n;i++) dfs(h,p,0,i),dfs(h,a,m-1,i);
        for(int i=0;i<m;i++) dfs(h,p,i,0),dfs(h,a,i,n-1);
        
        // for(int i=0;i<m;i++) 
        //     for(int j=0;j<n;j++) 
        //         if(a[i][j] && p[i][j]) ans.push_back({i,j});
        
        return ans;
    }
};