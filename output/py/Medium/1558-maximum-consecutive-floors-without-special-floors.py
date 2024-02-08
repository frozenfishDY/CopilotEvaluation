#https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
#Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be special floors, used for relaxation only.
#You are given two integers bottom and top, which denote that Alice has rented all the floors from bottom to top (inclusive). You are also given the integer array special, where special[i] denotes a special floor that Alice has designated for relaxation.
#Return the maximum number of consecutive floors without a special floor.


class Solution(object):
    def maxConsecutive(self, bottom, top, special):
        """
        :type bottom: int
        :type top: int
        :type special: List[int]
        :rtype: int
        """ 
        # 1. find the maximum consecutive floors without special floors
        # 2. return the maximum consecutive floors without special floors
        # 1. find the maximum consecutive floors without special floors
        # 2. return the maximum consecutive floors without special floors
        return self.maxConsecutiveFromIndex(bottom, top, special, 0, 0)

        
    