#https://leetcode.com/problems/partition-labels/
#You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
#Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
#Return a list of integers representing the size of these parts.
# 
#Example 1:
#Input: s = "ababcbacadefegdehijhklij"
#Output: [9,7,8]
#Explanation:
#The partition is "ababcbaca", "defegde", "hijhklij".
#This is a partition so that each letter appears in at most one part.
#A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
#Example 2:
#Input: s = "eccbbbbdec"
#Output: [10]
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of lowercase English letters.
class Solution(object):
    def partitionLabels(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        #Solution
        #1. Initialize the result to []
        #2. For each number in s, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #s: "ababcbacadefegdehijhklij"
        #ret: [9,7,8]
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = []
        for i in range(len(s)):
            for j in range(len(s[i])):
                if s[i][j] == 1:
                    if self.check(s, i, j):
                        ret += 1
        return ret