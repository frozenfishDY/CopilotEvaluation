#https://leetcode.com/problems/permutation-in-string/
#Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
#In other words, return true if one of s1's permutations is the substring of s2.
# 
#Example 1:
#Input: s1 = "ab", s2 = "eidbaooo"
#Output: true
#Explanation: s2 contains one permutation of s1 ("ba").
#Example 2:
#Input: s1 = "ab", s2 = "eidboaoo"
#Output: false
# 
#Constraints:
#	1 <= s1.length, s2.length <= 104
#	s1 and s2 consist of lowercase English letters.
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        #Solution
        #1. Initialize the two pointers to 0
        #2. Iterate through every character in s2
        #3. If the character is in s1, increment the pointer
        #4. If the pointer is equal to the length of s1, return True
        #5. Return False
        #
        #Example:
        #s1 = "ab", s2 = "eidbaooo"
        #i: 0
        #j: 0
        #i: 1
        #j: 1
        #i: 2
        #j: 2
        #i: 3
        #j: 3
        #i: 4
        #j: 4
        #i: 5
        #j: 5
        #i: 6
        #j: 6
        #i: 7
        #j: 7
        #i: 8
        #j: 8
        #i: 9
        #j: 9
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        i = 0
        j = 0
        while j < len(s2):
            if s2[j] in s1:
                j += 1
            else:
                j += 1
                i = j
            if j - i == len(s1):
                return True
        return False
        