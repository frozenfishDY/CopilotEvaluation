#https://leetcode.com/problems/reverse-words-in-a-string-iii/
#Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """       
        res=""
        for i in s.split(" "):
            res=res+i[::-1]+" "
        return res[:-1]

    