#https://leetcode.com/problems/sum-of-even-numbers-after-queries/
#You are given an integer array nums and an array queries where queries[i] = [vali, indexi].
#For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.
#Return an integer array answer where answer[i] is the answer to the ith query.


class Solution(object):
    def sumEvenAfterQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        res = []
        for i in range(len(queries)):
            nums[queries[i][1]] += queries[i][0]
            res.append(sum([x for x in nums if x % 2 == 0]))
        return res
        

    