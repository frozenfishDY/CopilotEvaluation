#https://leetcode.com/problems/tallest-billboard/
#You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
#You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
#Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.


class Solution(object):
    def tallestBillboard(self, rods):
        """
        :type rods: List[int]
        :rtype: int
        """
        if not rods:
            return 0
        if len(rods)==1:
            return 0
        if len(rods)==2:
            if rods[0]==rods[1]:
                return rods[0]
            else:
                return 0
        result = 0
        for i in range(len(rods)):
            result = max(result,self.tallestBillboard(rods[:i]+rods[i+1:]))
        return result
        
        
    