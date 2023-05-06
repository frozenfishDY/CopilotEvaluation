#https://leetcode.com/problems/moving-stones-until-consecutive-ii/
#There are some stones in different positions on the X-axis. You are given an integer array stones, the positions of the stones.
#Call a stone an endpoint stone if it has the smallest or largest position. In one move, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.
#In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.
#The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
#Return an integer array answer of length 2 where:
#answer[0] is the minimum number of moves you can play, and
#answer[1] is the maximum number of moves you can play.


class Solution(object):
    def numMovesStonesII(self, stones):
        """
        :type stones: List[int]
        :rtype: List[int]
        """
        stones.sort()
        n = len(stones)
        max_move = max(stones[n-1] - stones[1] - n + 2, stones[n-2] - stones[0] - n + 2)
        min_move = n
        i = 0
        for j in range(n):
            while stones[j] - stones[i] >= n:
                i += 1
            if j - i + 1 == n - 1 and stones[j] - stones[i] == n - 2:
                min_move = min(min_move, 2)
            else:
                min_move = min(min_move, n - (j - i + 1))
        return [min_move, max_move]
        

    