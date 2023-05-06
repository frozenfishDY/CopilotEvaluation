#https://leetcode.com/problems/card-flipping-game/
#You are given two 0-indexed integer arrays fronts and backs of length n, where the ith card has the positive integer fronts[i] printed on the front and backs[i] printed on the back. Initially, each card is placed on a table such that the front number is facing up and the other is facing down. You may flip over any number of cards (possibly zero).
#After flipping the cards, an integer is considered good if it is facing down on some card and not facing up on any card.
#Return the minimum possible good integer after flipping the cards. If there are no good integers, return 0.


class Solution(object):
    def flipgame(self, fronts, backs):
        """
        :type fronts: List[int]
        :type backs: List[int]
        :rtype: int
        """
        good = set(range(1, 2001))
        for f, b in zip(fronts, backs):
            if f == b:
                good.discard(f)
        return min(good) if good else 0
        

    