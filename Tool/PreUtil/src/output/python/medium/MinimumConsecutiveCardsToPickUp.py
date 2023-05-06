#https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
#ou are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
#Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.


class Solution(object):
    def minimumCardPickup(self, cards):
        """
        :type cards: List[int]
        :rtype: int
        """ 
            
        # 1. sort the array
        # 2. find the minimum consecutive cards to pick up
        # 3. return the minimum number of consecutive cards to pick up
            
         # 1. sort the array
        cards.sort()
            
        # 2. find the minimum consecutive cards to pick up
        # 3. return the minimum number of consecutive cards to pick up
        return self.minimumCardPickupFromIndex(cards, 0, 0)
        
    