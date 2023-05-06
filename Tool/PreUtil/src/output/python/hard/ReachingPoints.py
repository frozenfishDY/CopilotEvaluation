#https://leetcode.com/problems/reaching-points/
#Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.
#The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).


class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        """
        :type sx: int
        :type sy: int
        :type tx: int
        :type ty: int
        :rtype: bool
        """
        # 1. if tx < sx or ty < sy, return false
        # 2. if tx == sx and ty == sy, return true
        # 3. if tx > ty, tx = tx - ty
        # 4. if tx < ty, ty = ty - tx
        # 5. repeat 1-4 until tx == sx and ty == sy
        # 6. return true
        # 7. if tx < sx or ty < sy, return false
        
        # 1. if tx < sx or ty < sy, return false
        if tx < sx or ty < sy:
            return False
        
        # 2. if tx == sx and ty == sy, return true
        if tx == sx and ty == sy:
            return True
        
        # 5. repeat 1-4 until tx == sx and ty == sy
        while tx != sx or ty != sy:
            # 3. if tx > ty, tx = tx - ty
            if tx > ty:
                tx = tx - ty
            # 4. if tx < ty, ty = ty - tx
            else:
                ty = ty - tx
        
        # 6. return true
        return True
        
        # 7. if tx < sx or ty < sy, return false
        if tx < sx or ty < sy:
            return False
        
        
    