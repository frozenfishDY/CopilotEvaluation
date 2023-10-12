#https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
#You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
#	nums.length == n
#	nums[i] is a positive integer where 0 <= i < n.
#	abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
#	The sum of all the elements of nums does not exceed maxSum.
#	nums[index] is maximized.
#Return nums[index] of the constructed array.
#Note that abs(x) equals x if x >= 0, and -x otherwise.
# 
#Example 1:
#Input: n = 4, index = 2,  maxSum = 6
#Output: 2
#Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
#There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
#Example 2:
#Input: n = 6, index = 1,  maxSum = 10
#Output: 3
# 
#Constraints:
#	1 <= n <= maxSum <= 109
#	0 <= index < n
class Solution(object):
    def maxValue(self, n, index, maxSum):
        """
        :type n: int
        :type index: int
        :type maxSum: int
        :rtype: int
        """
        def f(x):
            if x <= index:
                return (x + 1) * x // 2 + index - x
            else:
                return (n - x + 1 + n - index) * (x - index) // 2
        maxSum -= n
        l, r = 0, maxSum + 1
        while l < r:
            mid = (l + r + 1) >> 1
            if f(mid) <= maxSum:
                l = mid
            else:
                r = mid - 1
        return l + 1