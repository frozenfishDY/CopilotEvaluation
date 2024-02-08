#https://leetcode.com/problems/jump-game-iii/
#Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
#Notice that you can not jump outside of the array at any time.


class Solution(object):
    def canReach(self, arr, start):
        """
        :type arr: List[int]
        :type start: int
        :rtype: bool
        """
        if arr[start] == 0:
            return True
        if arr[start] == -1:
            return False
        arr[start] = -1
        return (start+arr[start] < len(arr) and self.canReach(arr,start+arr[start])) or (start-arr[start] >= 0 and self.canReach(arr,start-arr[start]))
        

    