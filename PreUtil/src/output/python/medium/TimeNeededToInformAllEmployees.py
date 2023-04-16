#https://leetcode.com/problems/time-needed-to-inform-all-employees/
#A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.
#Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.
#The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.
#The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).
#Return the number of minutes needed to inform all the employees about the urgent news.


class Solution(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        """
        :type n: int
        :type headID: int
        :type manager: List[int]
        :type informTime: List[int]
        :rtype: int
        """      
        # 1. Find the max number in the list
        # 2. If max number is equal to the length of the list, then return 1
        # 3. If max number is greater than the length of the list, then return 2
        # 4. If max number is less than the length of the list, then return 0
        max_num = max(flips)
        if max_num == len(flips):
            return 1
        elif max_num > len(flips):
            return 2
        else:
            return 0

        

    