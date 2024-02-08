#https://leetcode.com/problems/target-sum/
#You are given an integer array nums and an integer target.
#You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
#	For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
#Return the number of different expressions that you can build, which evaluates to target.
# 
#Example 1:
#Input: nums = [1,1,1,1,1], target = 3
#Output: 5
#Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
#-1 + 1 + 1 + 1 + 1 = 3
#+1 - 1 + 1 + 1 + 1 = 3
#+1 + 1 - 1 + 1 + 1 = 3
#+1 + 1 + 1 - 1 + 1 = 3
#+1 + 1 + 1 + 1 - 1 = 3
#Example 2:
#Input: nums = [1], target = 1
#Output: 1
# 
#Constraints:
#	1 <= nums.length <= 20
#	0 <= nums[i] <= 1000
#	0 <= sum(nums[i]) <= 1000
#	-1000 <= target <= 1000
class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """   
        #Solution
        #1. Initialize the result to 0
        #2. For each number in nums, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #nums: [1,1,1,1,1], target: 3
        #ret: 5
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = 0
        for num in nums:
            for i in range(len(ret)):
                if num >= ret[i][-1]:
                    ret.append(ret[i] + [num])
            ret.append([num])

        return [x for x in ret if len(x) > 1]