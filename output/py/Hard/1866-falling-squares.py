#https://leetcode.com/problems/falling-squares/
#There are several squares being dropped onto the X-axis of a 2D plane.
#You are given a 2D integer array positions where positions[i] = [lefti, sideLengthi] represents the ith square with a side length of sideLengthi that is dropped with its left edge aligned with X-coordinate lefti.
#Each square is dropped one at a time from a height above any landed squares. It then falls downward (negative Y direction) until it either lands on the top side of another square or on the X-axis. A square brushing the left/right side of another square does not count as landing on it. Once it lands, it freezes in place and cannot be moved.
#After each square is dropped, you must record the height of the current tallest stack of squares.
#Return an integer array ans where ans[i] represents the height described above after dropping the ith square.


class Solution(object):
    def fallingSquares(self, positions):
        """
        :type positions: List[List[int]]
        :rtype: List[int]
        """
        if not positions:
            return []
        if len(positions)==1:
            return [positions[0][1]]
        result=[]
        for i in range(len(positions)):
            result.append(self.fallingSquare(positions[:i+1]))
        return result
        
        
    