#https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
#Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
# 
#Example 1:
#Input: s = "bcabc"
#Output: "abc"
#Example 2:
#Input: s = "cbacdcbc"
#Output: "acdb"
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists of lowercase English letters.
# 
#Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
class Solution(object):
    def smallestSubsequence(self, s):
        """
        :type s: str
        :rtype: str
        """
        #Solution
        #1. Initialize the result to ""
        #2. For each number in s, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #s: "bcabc"
        #ret: "abc"
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = ""
        for num in s:
            for i in range(len(ret)):
                if num > ret[i]:
                    ret[i] = num

        return ret