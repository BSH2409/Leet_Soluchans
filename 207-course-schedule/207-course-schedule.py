class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        indegree, adj  = [0]*numCourses, defaultdict(list)
        
        for a,b in prerequisites:
            adj[b].append(a)
            indegree[a] += 1
        
        queue=[]
        count=0
        
        for i in range(numCourses):
            if indegree[i]==0:
                queue.append(i)
                count+=1

        while queue:
            cur = queue.pop(0)
            for i in adj[cur]:
                indegree[i] -=1
                if indegree[i] == 0:
                    queue.append(i)
                    count += 1
                    
        return count == numCourses