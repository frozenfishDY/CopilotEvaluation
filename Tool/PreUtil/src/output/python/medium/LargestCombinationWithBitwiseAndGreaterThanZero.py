#https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
#The bitwise AND of an array nums is the bitwise AND of all integers in nums.
#For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
#Also, for nums = [7], the bitwise AND is 7.
#You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.
#Return the size of the largest combination of candidates with a bitwise AND greater than 0.


class Solution(object):
    def largestCombination(self, candidates):
        """
        :type candidates: List[int]
        :rtype: int
        """      
        result=0
        for i in range(len(candidates)-1):
            for j in range(i+1,len(candidates)):
                if candidates[i]&candidates[j]>result:
                    result=candidates[i]&candidates[j]
        return result

        
    