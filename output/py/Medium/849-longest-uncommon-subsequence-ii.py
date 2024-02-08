#https://leetcode.com/problems/longest-uncommon-subsequence-ii/
#Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.
#An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.
#A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.
#	For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
# 
#Example 1:
#Input: strs = ["aba","cdc","eae"]
#Output: 3
#Example 2:
#Input: strs = ["aaa","aaa","aa"]
#Output: -1
# 
#Constraints:
#	2 <= strs.length <= 50
#	1 <= strs[i].length <= 10
#	strs[i] consists of lowercase English letters.
class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
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