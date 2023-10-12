#https://leetcode.com/problems/min-cost-to-connect-all-points/
#You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
#The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
#Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
# 
#Example 1:
#Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
#Output: 20
#Explanation: 
#We can connect the points as shown above to get the minimum cost of 20.
#Notice that there is a unique path between every pair of points.
#Example 2:
#Input: points = [[3,12],[-2,5],[-4,1]]
#Output: 18
# 
#Constraints:
#	1 <= points.length <= 1000
#	-106 <= xi, yi <= 106
#	All pairs (xi, yi) are distinct.
class Solution(object):
    def minCostConnectPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        dist = lambda x, y: abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1])
        res = 0
        n = len(points)
        visited = set()
        visited.add(0)
        pq = []
        for i in range(1, n):
            heapq.heappush(pq, (dist(0, i), i))
        while len(visited) < n:
            d, i = heapq.heappop(pq)
            if i in visited:
                continue
            visited.add(i)
            res += d
            for j in range(n):
                if j in visited:
                    continue
                heapq.heappush(pq, (dist(i, j), j))
        return res