class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n);
        for(auto &e:edges){
            int u=e[0],v=e[1];
            graph[u].push_back(v);graph[v].push_back(u);
            degree[u]++;degree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1)
                q.push(i);
        }
        while(n>2){
            n-=q.size();
            int s=q.size();
            while(s--){
                int u=q.front();
                q.pop();
                for(int v:graph[u]){
                    degree[v]--;
                    if(degree[v]==1)
                        q.push(v);
                }
            }
        }
        vector<int> ans;
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};