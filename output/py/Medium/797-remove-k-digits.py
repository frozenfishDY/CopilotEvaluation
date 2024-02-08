#https://leetcode.com/problems/remove-k-digits/
#Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.


class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        res = []
        for i, c in enumerate(num):
            while res and c < res[-1] and num.find(res[-1], i) != -1:
                res.pop()
            res.append(c)
        return "".join(res[:len(res)-k]).lstrip("0") or "0"
        

    