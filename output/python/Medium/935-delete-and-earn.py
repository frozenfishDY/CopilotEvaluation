#https://leetcode.com/problems/delete-and-earn/
#You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
#	Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
#Return the maximum number of points you can earn by applying the above operation some number of times.
# 
#Example 1:
#Input: nums = [3,4,2]
#Output: 6
#Explanation: You can perform the following operations:
#- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
#- Delete 2 to earn 2 points. nums = [].
#You earn a total of 6 points.
#Example 2:
#Input: nums = [2,2,3,3,3,4]
#Output: 9
#Explanation: You can perform the following operations:
#- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
#- Delete a 3 again to earn 3 points. nums = [3].
#- Delete a 3 once more to earn 3 points. nums = [].
#You earn a total of 9 points.
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	1 <= nums[i] <= 104
class Solution(object):
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in nums, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #nums: [3,4,2]
        #ret: 6
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = 0
        for i in range(len(nums)):
            for j in range(len(nums[i])):
                if nums[i][j] == 1:
                    if self.check(nums, i, j):
                        ret += 1
        return ret