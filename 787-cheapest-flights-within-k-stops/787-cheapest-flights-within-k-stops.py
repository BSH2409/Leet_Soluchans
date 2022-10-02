class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        if not flights or not flights[0]:
            return -1
        
        visited =[-1]*n
        adj = collections.defaultdict(list)
        for s, d, c in flights:
            adj[s].append([d, c])
        
        heap = [(0,src,0)] 

        while heap:
            cur_cost, cur_pos, cur_steps = heapq.heappop(heap)
           
            if cur_pos == dst:
                return cur_cost
            if cur_steps > k or (visited[cur_pos]!=-1 and visited[cur_pos]< cur_steps): 
                continue
            
            visited[cur_pos]=cur_steps
            
            for nextDst, nextCost in adj[cur_pos]: 
                heapq.heappush(heap, (cur_cost + nextCost, nextDst, cur_steps + 1))
        
        return -1