#https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
#Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
#Note that the subarray needs to be non-empty after deleting one element.
# 
#Example 1:
#Input: arr = [1,-2,0,3]
#Output: 4
#Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
#Example 2:
#Input: arr = [1,-2,-2,3]
#Output: 3
#Explanation: We just choose [3] and it's the maximum sum.
#Example 3:
#Input: arr = [-1,-1,-1,-1]
#Output: -1
#Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
# 
#Constraints:
#	1 <= arr.length <= 105
#	-104 <= arr[i] <= 104
class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        # Approach 1: Dynamic Programming
        # Time Complexity: O(N)
        # Space Complexity: O(1)
        # Runtime: 100 ms, faster than 100.00% of Python online submissions for Maximum Subarray Sum with One Deletion.
        # Memory Usage: 14.7 MB, less than 100.00% of Python online submissions for Maximum Subarray Sum with One Deletion.
        ans, take, skip = float('-inf'), float('-inf'), float('-inf')
        for a in arr:
            take, skip = max(take + a, a), max(skip + a, take)
            ans = max(ans, take, skip)
        return ans