#https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
#You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
#We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
# 
#Example 1:
#Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
#Output: [20,24]
#Explanation: 
#List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
#List 2: [0, 9, 12, 20], 20 is in range [20,24].
#List 3: [5, 18, 22, 30], 22 is in range [20,24].
#Example 2:
#Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
#Output: [1,1]
# 
#Constraints:
#	nums.length == k
#	1 <= k <= 3500
#	1 <= nums[i].length <= 50
#	-105 <= nums[i][j] <= 105
#	nums[i] is sorted in non-decreasing order.
class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
         #https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/discuss/104887/Python-Heap-based-solution
        heap = [(row[0], i, 0) for i, row in enumerate(nums)]
        heapq.heapify(heap)
        result = -1e9, 1e9
        right = max(row[0] for row in nums)
        while heap:
            left, i, j = heapq.heappop(heap)
            if right - left < result[1] - result[0]:
                result = left, right
            if j + 1 == len(nums[i]):
                return result
            v = nums[i][j + 1]
            right = max(right, v)
            heapq.heappush(heap, (v, i, j + 1))