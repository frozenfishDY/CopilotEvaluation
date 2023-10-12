#https://leetcode.com/problems/task-scheduler/
#Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
#However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
#Return the least number of units of times that the CPU will take to finish all the given tasks.
# 
#Example 1:
#Input: tasks = ["A","A","A","B","B","B"], n = 2
#Output: 8
#Explanation: 
#A -> B -> idle -> A -> B -> idle -> A -> B
#There is at least 2 units of time between any two same tasks.
#Example 2:
#Input: tasks = ["A","A","A","B","B","B"], n = 0
#Output: 6
#Explanation: On this case any permutation of size 6 would work since n = 0.
#["A","A","A","B","B","B"]
#["A","B","A","B","A","B"]
#["B","B","B","A","A","A"]
#...
#And so on.
#Example 3:
#Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
#Output: 16
#Explanation: 
#One possible solution is
#A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
# 
#Constraints:
#	1 <= task.length <= 104
#	tasks[i] is upper-case English letter.
#	The integer n is in the range [0, 100].
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        #Solution
        #1. Initialize the result to -1
        #2. For each number in nums, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #nums: [2,6,4,8,10,9,15]
        #ret: 5
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = [-1] * len(nums)
        for num in nums:
            for i in range(len(ret)):
                if num > ret[i]:
                    ret[i] = num

        return ret