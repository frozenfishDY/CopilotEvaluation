#https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
#You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.
#Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.


class Solution(object):
    def minimumRounds(self, tasks):
        """
        :type tasks: List[int]
        :rtype: int
        """
        result=0
        while len(tasks)>0:
            if len(set(tasks))==1:
                result+=1
                tasks=[]
            else:
                for i in range(len(tasks)):
                    if tasks[i]%2==1:
                        tasks[i]+=1
                tasks=[tasks[i]//2 for i in range(len(tasks))]
                result+=1
        return result
        
    