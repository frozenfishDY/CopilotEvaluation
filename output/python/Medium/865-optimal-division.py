#https://leetcode.com/problems/optimal-division/
#You are given an integer array nums. The adjacent integers in nums will perform the float division.
#	For example, for nums = [2,3,4], we will evaluate the expression "2/3/4".
#However, you can add any number of parenthesis at any position to change the priority of operations. You want to add these parentheses such the value of the expression after the evaluation is maximum.
#Return the corresponding expression that has the maximum value in string format.
#Note: your expression should not contain redundant parenthesis.
# 
#Example 1:
#Input: nums = [1000,100,10,2]
#Output: "1000/(100/10/2)"
#Explanation: 1000/(100/10/2) = 1000/((100/10)/2) = 200
#However, the bold parenthesis in "1000/((100/10)/2)" are redundant since they do not influence the operation priority.
#So you should return "1000/(100/10/2)".
#Other cases:
#1000/(100/10)/2 = 50
#1000/(100/(10/2)) = 50
#1000/100/10/2 = 0.5
#1000/100/(10/2) = 2
#Example 2:
#Input: nums = [2,3,4]
#Output: "2/(3/4)"
#Explanation: (2/(3/4)) = 8/3 = 2.667
#It can be shown that after trying all possibilities, we cannot get an expression with evaluation greater than 2.667
# 
#Constraints:
#	1 <= nums.length <= 10
#	2 <= nums[i] <= 1000
#	There is only one optimal division for the given input.
class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        #Solution
        #1. If there are 2 or less numbers in nums, return the result
        #2. If there are more than 2 numbers in nums, return the result
        #3. Return the result
        #
        #Example:
        #nums: [1000,100,10,2]
        #ret: "1000/(100/10/2)"
        #
        #Time complexity: O(n)
        #Space complexity: O(1)
        
        if len(nums) <= 2:
            return "/".join(map(str, nums))
        else:
            return str(nums[0]) + "/(" + "/".join(map(str, nums[1:])) + ")"
