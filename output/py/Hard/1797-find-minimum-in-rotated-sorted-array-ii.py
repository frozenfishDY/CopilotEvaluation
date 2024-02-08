#https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
#Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
#[4,5,6,7,0,1,4] if it was rotated 4 times.
#[0,1,4,4,5,6,7] if it was rotated 7 times.
#Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
#Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
#You must decrease the overall operation steps as much as possible.


class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """       
        if not nums:
            return 0
        # initialize the left index
        left = 0
        # initialize the right index
        right = len(nums) - 1
        # while the left index is less than the right index
        while left < right:
            # initialize the middle index
            mid = (left + right) // 2
            # if the middle index is greater than the right index
            if nums[mid] > nums[right]:
                # set the left index to the middle index plus 1
                left = mid + 1
            # if the middle index is less than the right index
            elif nums[mid] < nums[right]:
                # set the right index to the middle index
                right = mid
            # if the middle index is equal to the right index
            else:
                # set the right index to the right index minus 1
                right -= 1
        # return the left index
        return nums[left]

        
        
    