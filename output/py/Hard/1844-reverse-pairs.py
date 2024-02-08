#https://leetcode.com/problems/reverse-pairs/
#Given an integer array nums, return the number of reverse pairs in the array.
#A reverse pair is a pair (i, j) where:
#	0 <= i < j < nums.length and
#	nums[i] > 2 * nums[j].
# 
#Example 1:
#Input: nums = [1,3,2,3,1]
#Output: 2
#Explanation: The reverse pairs are:
#(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
#(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
#Example 2:
#Input: nums = [2,4,3,5,1]
#Output: 3
#Explanation: The reverse pairs are:
#(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
#(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
#(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
# 
#Constraints:
#	1 <= nums.length <= 5 * 104
#	-231 <= nums[i] <= 231 - 1
class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #https://leetcode.com/problems/reverse-pairs/discuss/97268/Python-merge-sort-solution
        def mergeSort(nums):
            if len(nums) <= 1:
                return 0
            mid = len(nums) / 2
            left = mergeSort(nums[:mid])
            right = mergeSort(nums[mid:])
            result = left + right
            i = j = 0
            while i < mid and j < len(nums):
                if nums[i] > 2 * nums[j]:
                    result += mid - i
                    j += 1
                else:
                    i += 1
            nums.sort()
            return result
        return mergeSort(nums)