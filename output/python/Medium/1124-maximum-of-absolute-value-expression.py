#https://leetcode.com/problems/maximum-of-absolute-value-expression/
#Given two arrays of integers with equal lengths, return the maximum value of:_x000D_
#_x000D_
#|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|_x000D_
#_x000D_
#where the maximum is taken over all 0 <= i, j < arr1.length._x000D_
# 
#Example 1:
#Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
#Output: 13
#Example 2:
#Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
#Output: 20
# 
#Constraints:
#	2 <= arr1.length == arr2.length <= 40000
#	-10^6 <= arr1[i], arr2[i] <= 10^6
class Solution(object):
    def maxAbsValExpr(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        # Approach 1: Brute Force
        # Time Complexity: O(N^2)
        # Space Complexity: O(1)
        # Runtime: 1084 ms, faster than 22.22% of Python online submissions for Maximum of Absolute Value Expression.
        # Memory Usage: 14.2 MB, less than 100.00% of Python online submissions for Maximum of Absolute Value Expression.
        # ans = 0
        # for i in range(len(arr1)):
        #     for j in range(i + 1, len(arr1)):
        #         ans = max(ans, abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j))
        # return ans

        # Approach 2: Max and Min
        # Time Complexity: O(N)
        # Space Complexity: O(1)
        # Runtime: 148 ms, faster than 100.00% of Python online submissions for Maximum of Absolute Value Expression.
        # Memory Usage: 14.2 MB, less than 100.00% of Python online submissions for Maximum of Absolute Value Expression.
        ans = 0
        for p, q in [[1, 1], [1, -1], [-1, 1], [-1, -1]]:
            closest = p * arr1[0] + q * arr2[0] + 0
            for i in range(1, len(arr1)):
                cur = p * arr1[i] + q * arr2[i] + i
                ans = max(ans, cur - closest)
                closest = min(closest, cur)
        return ans
