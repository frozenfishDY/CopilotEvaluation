#https://leetcode.com/problems/longest-substring-without-repeating-characters/
#Given a string s, find the length of the longest substring without repeating characters.


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """       
        res = 0
        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                if len(set(s[i:j])) == j-i:
                    res = max(res,j-i)
        return res
        

    