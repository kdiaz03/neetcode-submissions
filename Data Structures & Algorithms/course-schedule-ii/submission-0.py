class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0] * numCourses
        adj_list = {}

        for u, v in prerequisites:
            indegree[u] += 1
            if v in adj_list:
                adj_list[v].append(u)
            else:
                adj_list[v] = [u]
            
        queue = deque([n for n in range(numCourses) if indegree[n] == 0])

        order = []
        while queue:
            u = queue.popleft()
            order.append(u)

            for neighbor in adj_list.get(u, []):
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        
        return order if len(order) == numCourses else []