class Solution {
public:
    int max_depth;
    int far_node;
    void dfs(int s, vector<bool> &visited, vector< vector<int> > &adj, int depth, vector<int> &path) {
        visited[s] = true;
        if(max_depth < depth) {
            max_depth = depth;
            far_node = s;
        }
        for(auto i : adj[s]) {
            if(!visited[i]) {
                path[i] = s;
                dfs(i, visited, adj, depth+1, path);
            }
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        far_node = 0;
        max_depth = 0;
        vector<int> path(n, -1);
        vector<bool> visited(n);
        dfs(0, visited, adj, 0, path);
        max_depth = -1;
        visited=vector(n,false);
        path=vector(n,-1);
        dfs(far_node, visited, adj, 0, path);
        int u = far_node;
        int depth = 0;
        vector<int> res;
        while(u != -1) {
            if(max_depth % 2) {
                if(depth == (max_depth / 2) || depth == ((max_depth + 1) / 2)) {
                    res.push_back(u);
                }
            } else {
                if(depth == (max_depth / 2)) {
                    res.push_back(u);
                }
            }
            depth++;
            u = path[u];
        }
        return res;
    }
};