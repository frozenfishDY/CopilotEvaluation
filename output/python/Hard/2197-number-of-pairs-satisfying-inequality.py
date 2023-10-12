#https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
#You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:
#	0 <= i < j <= n - 1 and
#	nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
#Return the number of pairs that satisfy the conditions.
# 
#Example 1:
#Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
#Output: 3
#Explanation:
#There are 3 pairs that satisfy the conditions:
#1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
#2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
#3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
#Therefore, we return 3.
#Example 2:
#Input: nums1 = [3,-1], nums2 = [-2,2], diff = -1
#Output: 0
#Explanation:
#Since there does not exist any pair that satisfies the conditions, we return 0.
# 
#Constraints:
#	n == nums1.length == nums2.length
#	2 <= n <= 105
#	-104 <= nums1[i], nums2[i] <= 104
#	-104 <= diff <= 104
class Solution(object):
    def numberOfPairs(self, nums1, nums2, diff):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type diff: int
        :rtype: int
        """
        n = len(nums1)
        if n < 2:
            return 0
        ans = 0
        for i in range(n - 1):
            for j in range(i + 1, n):
                if nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff:
                    ans += 1
        return ans