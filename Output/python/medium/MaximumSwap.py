#https://leetcode.com/problems/maximum-swap/
#You are given an integer num. You can swap two digits at most once to get the maximum valued number.
#Return the maximum valued number you can get.


class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        res = 0
        for i in range(len(num)):
            for j in range(i+1,len(num)):
                if abs(num[i]-num[j]) > res:
                    res = abs(num[i]-num[j])
        return res
        

    