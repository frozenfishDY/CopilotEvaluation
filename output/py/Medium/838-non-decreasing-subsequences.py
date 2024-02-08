#https://leetcode.com/problems/non-decreasing-subsequences/
#Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
# 
#Example 1:
#Input: nums = [4,6,7,7]
#Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
#Example 2:
#Input: nums = [4,4,3,2,1]
#Output: [[4,4]]
# 
#Constraints:
#	1 <= nums.length <= 15
#	-100 <= nums[i] <= 100
class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        #Solution
        #1. For each number in nums, check if it is greater than the last number in each subsequence
        #2. If it is, add the new subsequence to the result
        #3. Return the result
        #
        #Example:
        #nums: [4,6,7,7]
        #ret: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = []
        for num in nums:
            for i in range(len(ret)):
                if num >= ret[i][-1]:
                    ret.append(ret[i] + [num])
            ret.append([num])

        return [x for x in ret if len(x) > 1]