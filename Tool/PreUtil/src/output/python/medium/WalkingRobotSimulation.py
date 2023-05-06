#https://leetcode.com/problems/walking-robot-simulation/
#A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:
#-2: Turn left 90 degrees.
#-1: Turn right 90 degrees.
#1 <= k <= 9: Move forward k units, one unit at a time.
#Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.
#Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).
#Note:
#North means +Y direction.
#East means +X direction.
#South means -Y direction.
#West means -X direction.


class Solution(object):
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """                                                                                    
        res = 0
        x = y = 0
        dx = 0
        dy = 1
        obstacles = set(map(tuple, obstacles))
        for command in commands:
            if command == -2:
                dx, dy = -dy, dx
            elif command == -1:
                dx, dy = dy, -dx
            else:
                for _ in range(command):
                    if (x + dx, y + dy) not in obstacles:
                        x += dx
                        y += dy
                        res = max(res, x * x + y * y)
        return res  














        

    