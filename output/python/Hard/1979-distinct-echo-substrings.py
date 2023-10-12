#https://leetcode.com/problems/distinct-echo-substrings/
#Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).
# 
#Example 1:
#Input: text = "abcabcabc"
#Output: 3
#Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
#Example 2:
#Input: text = "leetcodeleetcode"
#Output: 2
#Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
# 
#Constraints:
#	1 <= text.length <= 2000
#	text has only lowercase English letters.
class Solution(object):
    def distinctEchoSubstrings(self, text):
        """
        :type text: str
        :rtype: int
        """
        #DP
        #Time:  O(n^2)
        #Space: O(n)
        result = set()
        for i in range(len(text) - 1):
            for j in range(i + 1, len(text), 2):
                if text[i:(i + j - i) // 2] == text[(i + j - i) // 2:j]:
                    result.add(text[i:j])
        return len(result)