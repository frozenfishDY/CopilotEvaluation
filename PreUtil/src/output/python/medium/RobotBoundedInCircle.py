#https://leetcode.com/problems/robot-bounded-in-circle/
#On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:
#The north direction is the positive direction of the y-axis.
#The south direction is the negative direction of the y-axis.
#The east direction is the positive direction of the x-axis.
#The west direction is the negative direction of the x-axis.
#The robot can receive one of three instructions:
#"G": go straight 1 unit.
#"L": turn 90 degrees to the left (i.e., anti-clockwise direction).
#"R": turn 90 degrees to the right (i.e., clockwise direction).
#The robot performs the instructions given in order, and repeats them forever.
#Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.


class Solution(object):
    def isRobotBounded(self, instructions):
        """
        :type instructions: str
        :rtype: bool
        """
        x = y = 0
        dx = 0
        dy = 1
        for i in instructions:
            if i == 'G':
                x += dx
                y += dy
            elif i == 'L':
                dx, dy = -dy, dx
            else:
                dx, dy = dy, -dx
        return (x == 0 and y == 0) or (dx != 0 or dy != 1)
        

    