#https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/
#You are given a string s (0-indexed) you are asked to perform the following operation on s until you get a sorted string:
#Find the largest index i such that 1 <= i < s.length and s[i] < s[i - 1].
#Find the largest index j such that i <= j < s.length and s[k] < s[i - 1] for all the possible values of k in the range [i, j] inclusive.
#Swap the two characters at indices i - 1 and j.
#Reverse the suffix starting at index i.
#Return the number of operations needed to make the string sorted. Since the answer can be too large, return it modulo 10^9 + 7.


class Solution(object):
    def makeStringSorted(self, s):
        """
        :type s: str
        :rtype: int
        """      
        return 0
    
        
        
    