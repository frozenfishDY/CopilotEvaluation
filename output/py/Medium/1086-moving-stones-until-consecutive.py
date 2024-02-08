#https://leetcode.com/problems/moving-stones-until-consecutive/
#There are three stones in different positions on the X-axis. You are given three integers a, b, and c, the positions of the stones.
#In one move, you pick up a stone at an endpoint (i.e., either the lowest or highest position stone), and move it to an unoccupied position between those endpoints. Formally, let's say the stones are currently at positions x, y, and z with x < y < z. You pick up the stone at either position x or position z, and move that stone to an integer position k, with x < k < z and k != y.
#The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
#Return an integer array answer of length 2 where:
#answer[0] is the minimum number of moves you can play, and
#answer[1] is the maximum number of moves you can play.


class Solution(object):
    def numMovesStones(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        a, b, c = sorted([a, b, c])
        if b - a == 1 and c - b == 1:
            return [0, 0]
        if b - a <= 2 or c - b <= 2:
            return [1, c - a - 2]
        return [2, c - a - 2]
        

    