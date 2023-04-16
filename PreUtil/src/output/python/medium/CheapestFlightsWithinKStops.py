#https://leetcode.com/problems/cheapest-flights-within-k-stops/
#There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
#You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type k: int
        :rtype: int
        """       
        graph = collections.defaultdict(dict)
        for u, v, w in flights:
            graph[u][v] = w
        heap = [(0, src, k+1)]
        while heap:
            price, node, stops = heapq.heappop(heap)
            if node == dst:
                return price
            if stops > 0:
                for nei in graph[node]:
                    heapq.heappush(heap, (price+graph[node][nei], nei, stops-1))
        return -1

        

    