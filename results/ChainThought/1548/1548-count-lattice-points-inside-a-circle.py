#https://leetcode.com/problems/count-lattice-points-inside-a-circle/
#Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number of lattice points that are present inside at least one circle.
#Note:
#A lattice point is a point with integer coordinates.
#Points that lie on the circumference of a circle are also considered to be inside it.


class Solution(object):
    def countLatticePoints(self, circles):
        """
        :type circles: List[List[int]]
        :rtype: int
        """
        result=0
        for i in range(len(circles)):
            for j in range(i+1,len(circles)):
                if circles[i][0]==circles[j][0] and circles[i][1]==circles[j][1]:
                    result+=1
                elif circles[i][0]==circles[j][0]:
                    result+=1
                elif circles[i][1]==circles[j][1]:
                    result+=1
                else:
                    result+=1
        return result
        
    