#https://leetcode.com/problems/course-schedule/
#There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
#For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
#Return true if you can finish all courses. Otherwise, return false.


class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """      
        graph = [[] for _ in range(numCourses)]
        visited = [0 for _ in range(numCourses)]
        for i,j in prerequisites:
            graph[i].append(j)
        def dfs(i):
            if visited[i]==-1:
                return False
            if visited[i]==1:
                return True
            visited[i] = -1
            for j in graph[i]:
                if not dfs(j):
                    return False
            visited[i] = 1
            return True
        for i in range(numCourses):
            if not dfs(i):
                return False
        return True
        

    