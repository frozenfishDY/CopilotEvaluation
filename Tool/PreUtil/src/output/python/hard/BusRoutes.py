#https://leetcode.com/problems/bus-routes/
#You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
#For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
#You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
#Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.


class Solution(object):
    def numBusesToDestination(self, routes, source, target):
        """
        :type routes: List[List[int]]
        :type source: int
        :type target: int
        :rtype: int
        """
        if source==target:
            return 0
        routes_dict={}
        for i in range(len(routes)):
            for j in range(len(routes[i])):
                if routes[i][j] in routes_dict:
                    routes_dict[routes[i][j]].append(i)
                else:
                    routes_dict[routes[i][j]]=[i]
        visited=set()
        queue=[source]
        count=0
        while queue:
            count+=1
            for i in range(len(queue)):
                current=queue.pop(0)
                for j in routes_dict[current]:
                    if j not in visited:
                        visited.add(j)
                        for k in range(len(routes[j])):
                            if routes[j][k]==target:
                                return count
                            queue.append(routes[j][k])
        return -1
        
        
    