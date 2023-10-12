#https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
#Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.
#An array A is a zigzag array if either:
#	Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
#	OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
#Return the minimum number of moves to transform the given array nums into a zigzag array.
# 
#Example 1:
#Input: nums = [1,2,3]
#Output: 2
#Explanation: We can decrease 2 to 0 or 3 to 1.
#Example 2:
#Input: nums = [9,6,1,6,2]
#Output: 4
# 
#Constraints:
#	1 <= nums.length <= 1000
#	1 <= nums[i] <= 1000
class Solution(object):
    def movesToMakeZigzag(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Approach 1: Greedy
        # Time Complexity: O(N)
        # Space Complexity: O(1)
        # Runtime: 28 ms, faster than 94.44% of Python online submissions for Decrease Elements To Make Array Zigzag.
        # Memory Usage: 13 MB, less than 100.00% of Python online submissions for Decrease Elements To Make Array Zigzag.
        ans = [0, 0]
        for i, num in enumerate(nums):
            left = nums[i - 1] if i > 0 else float('inf')
            right = nums[i + 1] if i < len(nums) - 1 else float('inf')
            ans[i % 2] += max(0, num - min(left, right) + 1)
        return min(ans)