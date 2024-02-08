#https://leetcode.com/problems/k-diff-pairs-in-an-array/
#Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
#A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
#	0 <= i, j < nums.length
#	i != j
#	|nums[i] - nums[j]| == k
#Notice that |val| denotes the absolute value of val.
# 
#Example 1:
#Input: nums = [3,1,4,1,5], k = 2
#Output: 2
#Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
#Although we have two 1s in the input, we should only return the number of unique pairs.
#Example 2:
#Input: nums = [1,2,3,4,5], k = 1
#Output: 4
#Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
#Example 3:
#Input: nums = [1,3,1,5,4], k = 0
#Output: 1
#Explanation: There is one 0-diff pair in the array, (1, 1).
# 
#Constraints:
#	1 <= nums.length <= 104
#	-107 <= nums[i] <= 107
#	0 <= k <= 107
class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #Solution
        #1. For each number in nums, mark the number at index abs(num) - 1 as negative
        #2. If the number at index abs(num) - 1 is already negative, add abs(num) to result
        #3. Return the result
        #
        #Example:
        #nums: [4,3,2,7,8,2,3,1]
        #ret: [2,3]
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        ret = []
        for num in nums:
            index = abs(num) - 1
            if nums[index] < 0:
                ret.append(abs(num))
            else:
                nums[index] = -nums[index]

        return ret