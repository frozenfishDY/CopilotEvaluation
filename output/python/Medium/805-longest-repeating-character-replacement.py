#https://leetcode.com/problems/longest-repeating-character-replacement/
#You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
#Return the length of the longest substring containing the same letter you can get after performing the above operations.
# 
#Example 1:
#Input: s = "ABAB", k = 2
#Output: 4
#Explanation: Replace the two 'A's with two 'B's or vice versa.
#Example 2:
#Input: s = "AABABBA", k = 1
#Output: 4
#Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
#The substring "BBBB" has the longest repeating letters, which is 4.
#There may exists other ways to achive this answer too.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of only uppercase English letters.
#	0 <= k <= s.length
class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """ 
        #Solution
        #1. Initialize the maximum length to 0
        #2. Iterate through every character in s
        #3. For each character, find the maximum length of repeating characters
        #4. Return the maximum length
        #
        #Example:
        #s = "ABAB", k = 2
        #maxLength: 0
        #i: 0
        #maxLength: 1
        #i: 1
        #maxLength: 2
        #i: 2
        #maxLength: 3
        #i: 3
        #maxLength: 4
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        maxLength = 0
        for i in range(len(s)):
            maxCount = 0
            for j in range(i, len(s)):
                if s[j] == s[i]:
                    maxCount += 1
                elif k > 0:
                    maxCount += 1
                    k -= 1
                else:
                    break

            maxLength = max(maxLength, maxCount)

        return maxLength