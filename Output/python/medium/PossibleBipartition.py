#https://leetcode.com/problems/possible-bipartition/
#We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
#Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.


class Solution(object):
    def possibleBipartition(self, n, dislikes):
        """
        :type n: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        if n == 0:
            return True
        if len(dislikes) == 0:
            return True
        graph = {}
        for i in range(1, n + 1):
            graph[i] = []
        for dislike in dislikes:
            graph[dislike[0]].append(dislike[1])
            graph[dislike[1]].append(dislike[0])
        color = {}
        for i in range(1, n + 1):
            color[i] = -1
        for i in range(1, n + 1):
            if color[i] == -1:
                color[i] = 0
                queue = []
                queue.append(i)
                while len(queue) > 0:
                    node = queue.pop(0)
                    for neighbor in graph[node]:
                        if color[neighbor] == -1:
                            color[neighbor] = 1 - color[node]
                            queue.append(neighbor)
                        elif color[neighbor] == color[node]:
                            return False
        return True
        

    