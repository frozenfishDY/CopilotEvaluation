#https://leetcode.com/problems/maximum-score-from-removing-substrings/
#You are given a string s and two integers x and y. You can perform two types of operations any number of times.
#Remove substring "ab" and gain x points.
#For example, when removing "ab" from "cabxbae" it becomes "cxbae".
#Remove substring "ba" and gain y points.
#For example, when removing "ba" from "cabxbae" it becomes "cabxe".
#Return the maximum points you can gain after applying the above operations on s.


class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        result=0
        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                if len(set(s[i:j]))==len(s[i:j]):
                    result=max(result,sum(s[i:j]))
        return result
        

    