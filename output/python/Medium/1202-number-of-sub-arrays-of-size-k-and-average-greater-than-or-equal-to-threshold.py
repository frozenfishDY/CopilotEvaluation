#https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
#Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.
# 
#Example 1:
#Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
#Output: 3
#Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
#Example 2:
#Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
#Output: 6
#Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
# 
#Constraints:
#	1 <= arr.length <= 105
#	1 <= arr[i] <= 104
#	1 <= k <= arr.length
#	0 <= threshold <= 104
class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        # Approach 1: Sliding Window
        # Time Complexity: O(N)
        # Space Complexity: O(1)
        # Runtime: 916 ms, faster than 20.00% of Python online submissions for Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.
        # Memory Usage: 25.2 MB, less than 20.00% of Python online submissions for Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.
        ans = 0
        window_sum = sum(arr[:k])
        for i in range(k, len(arr)):
            if window_sum >= threshold * k:
                ans += 1
            window_sum += arr[i] - arr[i - k]
        if window_sum >= threshold * k:
            ans += 1
        return ans