#https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
#In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
#We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
#Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
#If it cannot be done, return -1.


class Solution(object):
    def minDominoRotations(self, tops, bottoms):
        """
        :type tops: List[int]
        :type bottoms: List[int]
        :rtype: int
        """
        if len(tops) == 1:
            return 0
        if tops[0] == bottoms[0]:
            return self.minDominoRotationsHelper(tops, bottoms, tops[0])
        else:
            return min(self.minDominoRotationsHelper(tops, bottoms, tops[0]), self.minDominoRotationsHelper(tops, bottoms, bottoms[0]))
        

    