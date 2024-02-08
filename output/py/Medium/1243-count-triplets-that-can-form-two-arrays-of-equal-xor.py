#https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
#Given an array of integers arr.
#We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
#Let's define a and b as follows:
#	a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
#	b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
#Note that ^ denotes the bitwise-xor operation.
#Return the number of triplets (i, j and k) Where a == b.
# 
#Example 1:
#Input: arr = [2,3,1,6,7]
#Output: 4
#Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
#Example 2:
#Input: arr = [1,1,1,1,1]
#Output: 10
# 
#Constraints:
#	1 <= arr.length <= 300
#	1 <= arr[i] <= 108
class Solution(object):
    def countTriplets(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        count, length = 0, len(arr)
        for i in range(length):
            temp = arr[i]
            for j in range(i + 1, length):
                temp ^= arr[j]
                if temp == 0:
                    count += j - i
        return count