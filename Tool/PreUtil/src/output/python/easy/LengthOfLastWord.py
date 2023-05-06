#https://leetcode.com/problems/length-of-last-word/
#Given a string s consisting of words and spaces, return the length of the last word in the string.
#A word is a maximal substring consisting of non-space characters only.


class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s)==0:
            return 0
        else:
            str=s.split()
            if len(str)==0:
                return 0
            else:
                return len(str[len(str)-1])

    