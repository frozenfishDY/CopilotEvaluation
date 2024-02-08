#https://leetcode.com/problems/largest-divisible-subset/
#Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
#	answer[i] % answer[j] == 0, or
#	answer[j] % answer[i] == 0
#If there are multiple solutions, return any of them.
# 
#Example 1:
#Input: nums = [1,2,3]
#Output: [1,2]
#Explanation: [1,3] is also accepted.
#Example 2:
#Input: nums = [1,2,4,8]
#Output: [1,2,4,8]
# 
#Constraints:
#	1 <= nums.length <= 1000
#	1 <= nums[i] <= 2 * 109
#	All the integers in nums are unique.
class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #Solution
        #1. Sort the array nums
        #2. For each element in nums, find the length of largest subset and save in count[]
        #3. Pick the index of the largest element in count.
        #4. From nums[maxIndex] to 0, add every element belongs to the largest subset.
        #5. Return the result
        #
        #Example:
        #nums: [1,2,3,4,6,8,12,24]
        #count:[1,2,2,3,3,4,4,5]
        #maxIndex = 7
        #ret: [1,2,4,8,24]
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        nums.sort()
        count = [1] * len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and count[i] < count[j] + 1:
                    count[i] = count[j] + 1

        maxIndex = 0
        for i in range(1, len(count)):
            if count[i] > count[maxIndex]:
                maxIndex = i

        ret = []
        temp = nums[maxIndex]
        currCount = count[maxIndex]
        for i in range(maxIndex, -1, -1):
            if temp % nums[i] == 0 and count[i] == currCount:
                ret.append(nums[i])
                temp = nums[i]
                currCount -= 1

        return ret[::-1]