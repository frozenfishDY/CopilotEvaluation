#https://leetcode.com/problems/previous-permutation-with-one-swap/
#Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest permutation that is smaller than arr, that can be made with exactly one swap. If it cannot be done, then return the same array.
#Note that a swap exchanges the positions of two numbers arr[i] and arr[j]
# 
#Example 1:
#Input: arr = [3,2,1]
#Output: [3,1,2]
#Explanation: Swapping 2 and 1.
#Example 2:
#Input: arr = [1,1,5]
#Output: [1,1,5]
#Explanation: This is already the smallest permutation.
#Example 3:
#Input: arr = [1,9,4,6,7]
#Output: [1,7,4,6,9]
#Explanation: Swapping 9 and 7.
# 
#Constraints:
#	1 <= arr.length <= 104
#	1 <= arr[i] <= 104
class Solution(object):
    def prevPermOpt1(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        #Solution
        #1. Initialize the result to -1
        #2. For each number in arr, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #arr: [3,2,1]
        #ret: [3,1,2]
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = [-1] * len(arr)
        for num in arr:
            for i in range(len(ret)):
                if num > ret[i]:
                    ret[i] = num

        return ret