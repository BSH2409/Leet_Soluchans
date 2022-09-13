class Solution {
   public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        int[] indegree = new int[n];
        for (int[] e : edges) {
            int v = e[0], u = e[1];
            graph[v].add(u);graph[u].add(v);
            indegree[v]++;indegree[u]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int v = 0; v < n; v++) {
            if (indegree[v] <= 1) {
                queue.offer(v);
            }
        }
        
        List<Integer> res = new ArrayList<>();
        while (n>2) {
            n-=queue.size();
            int size=queue.size();
            while(size-- !=0) {
                int v = queue.poll();
                for (int u : graph[v]) {
                    if (--indegree[u] == 1) {
                        queue.add(u);
                    }
                }
            }
        }
        while(queue.size()!=0)
            res.add(queue.poll());
        return res;
    }
}