class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
    int[][] adj = new int[numCourses][numCourses];
    int[] indegree = new int[numCourses];
    int n = prerequisites.length;
    for(int i=0;i<n;i++){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[v][u] = 1;
        indegree[u] ++;
    }
    Queue<Integer> queue = new LinkedList<Integer>();

    for(int i=0;i<numCourses;i++){
        if(indegree[i] == 0){
            queue.add(i);
        }
    }
    int count = 0;
    while(!queue.isEmpty()){
        int cur = queue.poll();
        count += 1;
        for(int i = 0; i < numCourses;i++){
            if(adj[cur][i] == 1){
                indegree[i]--;
                if(indegree[i] == 0){
                    queue.add(i);
                }
            }
        }
    }
    return count == numCourses;
    
}
}