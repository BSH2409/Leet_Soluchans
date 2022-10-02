
class Solution:

    
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        prev_iter = [float('inf')] * n
        prev_iter[src] = 0
        
        for i in range(k + 1):

            cur_iter = list(prev_iter)
            for source, dest, cost in flights:
                current_cheapest = cur_iter[dest]
                new_price = prev_iter[source] + cost
                
                if new_price < current_cheapest:
                    cur_iter[dest] = new_price

            prev_iter = cur_iter
        
        return prev_iter[dst] if prev_iter[dst] != float('inf') else -1