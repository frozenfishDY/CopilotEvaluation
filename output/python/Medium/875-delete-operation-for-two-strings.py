#https://leetcode.com/problems/delete-operation-for-two-strings/
#Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
#In one step, you can delete exactly one character in either string.
# 
#Example 1:
#Input: word1 = "sea", word2 = "eat"
#Output: 2
#Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
#Example 2:
#Input: word1 = "leetcode", word2 = "etco"
#Output: 4
# 
#Constraints:
#	1 <= word1.length, word2.length <= 500
#	word1 and word2 consist of only lowercase English letters.
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. Iterate through every character in word1
        #3. If the character is in word2, increment the result
        #4. Return the result
        #
        #Example:
        #word1: "sea", word2: "eat"
        #ret: 2
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        ret = 0
        for c in word1:
            if c in word2:
                ret += 1

        return ret