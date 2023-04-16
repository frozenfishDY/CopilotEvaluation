#https://leetcode.com/problems/ones-and-zeroes/
#You are given an array of binary strings strs and two integers m and n.
#Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
#A set x is a subset of a set y if all elements of x are also elements of y.


class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        res = 0
        for i in range(len(strs)):
            for j in range(i+1,len(strs)):
                if strs[i] == strs[j]:
                    res += 1
        return res
        

    