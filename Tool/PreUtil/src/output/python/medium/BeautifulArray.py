#https://leetcode.com/problems/beautiful-array/
#An array nums of length n is beautiful if:
#nums is a permutation of the integers in the range [1, n].
#For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
#Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.


class Solution(object):
    def beautifulArray(self, n):
        """
        :type n: int
        :rtype: List[int]
        """       
        res = [1]
        while len(res) < n:
            res = [2 * i - 1 for i in res] + [2 * i for i in res]
        return [i for i in res if i <= n]

        

    