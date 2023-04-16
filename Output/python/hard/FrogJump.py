#https://leetcode.com/problems/frog-jump/
#A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
#Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
#If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.


class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        # initialize the dictionary
        d = {}
        # for each stone in the stones
        for stone in stones:
            # set the stone to an empty set
            d[stone] = set()
        # set the first stone to a set with 1
        d[0].add(1)
        # for each stone in the stones
        for stone in stones:
            # for each jump in the dictionary at the stone
            for jump in d[stone]:
                # if the stone plus the jump is in the dictionary
                if stone + jump in d:
                    # add the jump to the dictionary at the stone plus the jump
                    d[stone + jump].add(jump)
                    # if the jump minus 1 is greater than 0
                    if jump - 1 > 0:
                        # add the jump minus 1 to the dictionary at the stone plus the jump
                        d[stone + jump].add(jump - 1)
                    # add the jump plus 1 to the dictionary at the stone plus the jump
                    d[stone + jump].add(jump + 1)
        # return if the last stone in the stones is in the dictionary
        return len(d[stones[-1]]) > 0
        
        
    