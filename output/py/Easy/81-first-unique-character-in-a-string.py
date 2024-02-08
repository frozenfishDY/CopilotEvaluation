#https://leetcode.com/problems/first-unique-character-in-a-string/
#Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """ 
        if len(s)==0:
            return -1
        if len(s)==1:
            return 0
        for i in range(0,len(s)):
            if s.count(s[i])==1:
                return i
        return -1

    