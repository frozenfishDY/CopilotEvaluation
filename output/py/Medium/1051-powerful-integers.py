#https://leetcode.com/problems/powerful-integers/
#Given three integers x, y, and bound, return a list of all the powerful integers that have a value less than or equal to bound.
#An integer is powerful if it can be represented as xi + yj for some integers i >= 0 and j >= 0.
#You may return the answer in any order. In your answer, each value should occur at most once.


class Solution(object):
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        res = set()
        for i in range(20):
            for j in range(20):
                if x**i + y**j <= bound:
                    res.add(x**i + y**j)
                else:
                    break
        return list(res)
        

    