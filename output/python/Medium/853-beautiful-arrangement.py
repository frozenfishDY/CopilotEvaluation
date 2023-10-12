#https://leetcode.com/problems/beautiful-arrangement/
#Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
#	perm[i] is divisible by i.
#	i is divisible by perm[i].
#Given an integer n, return the number of the beautiful arrangements that you can construct.
# 
#Example 1:
#Input: n = 2
#Output: 2
#Explanation: 
#The first beautiful arrangement is [1,2]:
#    - perm[1] = 1 is divisible by i = 1
#    - perm[2] = 2 is divisible by i = 2
#The second beautiful arrangement is [2,1]:
#    - perm[1] = 2 is divisible by i = 1
#    - i = 2 is divisible by perm[2] = 1
#Example 2:
#Input: n = 1
#Output: 1
# 
#Constraints:
#	1 <= n <= 15
class Solution(object):
    def countArrangement(self, n):
        """
        :type n: int
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. Initialize the visited array to False
        #3. Recursively call the helper function and return the result
        #
        #Example:
        #n: 2
        #ret: 2
        #
        #Time complexity: O(n!)
        #Space complexity: O(n)
        
        def helper(n, visited):
            if n == 0:
                return 1
            result = 0
            for i in range(1, len(visited)):
                if not visited[i] and (i % n == 0 or n % i == 0):
                    visited[i] = True
                    result += helper(n - 1, visited)
                    visited[i] = False
            return result
        
        visited = [False] * (n + 1)
        return helper(n, visited)