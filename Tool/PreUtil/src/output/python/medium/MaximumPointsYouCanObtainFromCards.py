#https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
#There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
#In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
#Your score is the sum of the points of the cards you have taken.
#Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


class Solution(object):
    def maxScore(self, cardPoints, k):
        """
        :type cardPoints: List[int]
        :type k: int
        :rtype: int
        """
        # 1. Get the total sum of the card points
        # 2. Get the sum of the first k card points
        # 3. Get the sum of the last k card points
        # 4. Loop through the card points from the beginning and the end
        # 5. If the number of card points from the beginning is less than k, then subtract the card point from the beginning from the total sum and add the card point from the end to the total sum
        # 6. If the number of card points from the end is less than k, then subtract the card point from the end from the total sum and add the card point from the beginning to the total sum
        # 7. Return the maximum sum
        total_sum = sum(cardPoints)
        sum_from_beginning = sum(cardPoints[:k])
        sum_from_end = sum(cardPoints[-k:])
        for i in range(k):
            if i < k:
                total_sum -= cardPoints[i]
                total_sum += cardPoints[-(i + 1)]
            if i < k:
                total_sum -= cardPoints[-(i + 1)]
                total_sum += cardPoints[i]
        return max(sum_from_beginning, sum_from_end, total_sum)
        

    