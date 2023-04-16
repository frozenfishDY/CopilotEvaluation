#https://leetcode.com/problems/hand-of-straights/
#Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
#Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.


class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        """
        :type hand: List[int]
        :type groupSize: int
        :rtype: bool
        """     
        if len(hand) % groupSize != 0:
            return False
        hand.sort()
        while hand:
            first = hand.pop(0)
            for i in range(1, groupSize):
                if first + i not in hand:
                    return False
                hand.remove(first + i)
        return True

        

    