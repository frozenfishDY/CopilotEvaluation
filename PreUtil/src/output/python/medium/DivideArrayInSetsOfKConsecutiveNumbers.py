#https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
#Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
#Return true if it is possible. Otherwise, return false.


class Solution(object):
    def isPossibleDivide(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """ 
        if len(nums)%k != 0:
            return False
        nums.sort()
        while nums:
            start = nums[0]
            for i in range(k):
                if start+i not in nums:
                    return False
                nums.remove(start+i)
        return True

        

    