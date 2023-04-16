#https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
#There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
#Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
#Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


class Solution(object):
    def findTheCity(self, n, edges, distanceThreshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type distanceThreshold: int
        :rtype: int
        """       
        graph = collections.defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))
        res = [n] * n
        for i in range(n):
            q = [(0, i)]
            visited = set()
            while q:
                dist, node = heapq.heappop(q)
                if node in visited:
                    continue
                visited.add(node)
                res[i] -= 1
                for nei, d in graph[node]:
                    if nei not in visited and dist + d <= distanceThreshold:
                        heapq.heappush(q, (dist + d, nei))
        return res.index(min(res))

        

    