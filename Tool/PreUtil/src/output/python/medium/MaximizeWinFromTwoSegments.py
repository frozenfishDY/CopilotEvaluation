#https://leetcode.com/problems/maximize-win-from-two-segments/
#There are some prizes on the X-axis. You are given an integer array prizePositions that is sorted in non-decreasing order, where prizePositions[i] is the position of the ith prize. There could be different prizes at the same position on the line. You are also given an integer k.
#You are allowed to select two segments with integer endpoints. The length of each segment must be k. You will collect all prizes whose position falls within at least one of the two selected segments (including the endpoints of the segments). The two selected segments may intersect.
#For example if k = 2, you can choose segments [1, 3] and [2, 4], and you will win any prize i that satisfies 1 <= prizePositions[i] <= 3 or 2 <= prizePositions[i] <= 4.
#Return the maximum number of prizes you can win if you choose the two segments optimally.


class Solution(object):
    def maximizeWin(self, prizePositions, k):
        """
        :type prizePositions: List[int]
        :type k: int
        :rtype: int
        """
        res = 0
        for i in range(len(prizePositions)):
            left = i
            right = len(prizePositions)-1
            while left < right:
                mid = left + (right-left)//2
                if prizePositions[mid] - prizePositions[i] < k:
                    left = mid+1
                else:
                    right = mid
            res = max(res, left-i+1)
        return res
        

    