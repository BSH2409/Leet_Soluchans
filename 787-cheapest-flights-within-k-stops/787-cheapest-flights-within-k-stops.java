class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        
        ArrayList<int[]>[] adj = new ArrayList[n];
        for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for(int i = 0; i < flights.length; i++) 
            adj[flights[i][0]].add(new int[]{flights[i][1], flights[i][2]});
        
        int[] visited = new int[n];
        Arrays.fill(visited, -1);

        PriorityQueue<int[]> queue = new PriorityQueue<>((a,b) -> a[1] - b[1]);
        queue.offer(new int[]{src, 0, 0}); 
    
        while(!queue.isEmpty()) {
            int[] curr  = queue.poll();
            int cur_pos = curr[0];
            int cur_cost  = curr[1];
            int cur_steps   = curr[2];
            
            if(cur_pos == dst) return cur_cost;
            
            if(cur_steps > k || (visited[cur_pos]!= -1 && visited[cur_pos] < cur_steps)) continue;
            
            visited[cur_pos] = cur_steps;
            
            for(int[] e : adj[cur_pos]) {
                queue.offer(new int[]{e[0], cur_cost + e[1], cur_steps + 1});
            }
        }
        
        return -1;
    }
}