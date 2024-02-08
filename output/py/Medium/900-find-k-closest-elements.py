#https://leetcode.com/problems/find-k-closest-elements/
#Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
#An integer a is closer to x than an integer b if:
#	|a - x| < |b - x|, or
#	|a - x| == |b - x| and a < b
# 
#Example 1:
#Input: arr = [1,2,3,4,5], k = 4, x = 3
#Output: [1,2,3,4]
#Example 2:
#Input: arr = [1,2,3,4,5], k = 4, x = -1
#Output: [1,2,3,4]
# 
#Constraints:
#	1 <= k <= arr.length
#	1 <= arr.length <= 104
#	arr is sorted in ascending order.
#	-104 <= arr[i], x <= 104
class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
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