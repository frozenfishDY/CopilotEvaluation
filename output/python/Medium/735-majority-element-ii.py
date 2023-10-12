#https://leetcode.com/problems/majority-element-ii/
#Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
# 
#Example 1:
#Input: nums = [3,2,3]
#Output: [3]
#Example 2:
#Input: nums = [1]
#Output: [1]
#Example 3:
#Input: nums = [1,2]
#Output: [1,2]
# 
#Constraints:
#	1 <= nums.length <= 5 * 104
#	-109 <= nums[i] <= 109
# 
#Follow up: Could you solve the problem in linear time and in O(1) space?
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # 1. Boyer-Moore Voting Algorithm
        # https://leetcode.com/problems/majority-element-ii/discuss/63502/6-Suggested-Solutions-in-C%2B%2B-with-Explanations
        # 1.1. initialization
        candidate1, candidate2 = None, None
        count1, count2 = 0, 0
        # 1.2. voting
        for num in nums:
            if candidate1 == num:
                count1 += 1
            elif candidate2 == num:
                count2 += 1
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            elif count2 == 0:
                candidate2 = num
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1
        # 1.3. check
        res = []
        if nums.count(candidate1) > len(nums)//3:
            res.append(candidate1)
        if nums.count(candidate2) > len(nums)//3:
            res.append(candidate2)
        return res