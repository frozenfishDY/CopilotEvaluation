#https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
#Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
#The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
#Any two characters may be swapped, even if they are not adjacent.
# 
#Example 1:
#Input: s = "111000"
#Output: 1
#Explanation: Swap positions 1 and 4: "111000" -> "101010"
#The string is now alternating.
#Example 2:
#Input: s = "010"
#Output: 0
#Explanation: The string is already alternating, no swaps are needed.
#Example 3:
#Input: s = "1110"
#Output: -1
# 
#Constraints:
#	1 <= s.length <= 1000
#	s[i] is either '0' or '1'.
class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = collections.Counter(s)
        if abs(cnt['0'] - cnt['1']) > 1:
            return -1
        if cnt['0'] == cnt['1']:
            return min(self.helper(s, '0'), self.helper(s, '1'))
        if cnt['0'] > cnt['1']:
            return self.helper(s, '0')
        return self.helper(s, '1')
    def helper(self, s, c):
        res = 0
        for i in range(len(s)):
            if i % 2 == 0:
                if s[i] != c:
                    res += 1
        return res