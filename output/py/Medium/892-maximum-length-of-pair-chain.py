#https://leetcode.com/problems/maximum-length-of-pair-chain/
#You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
#A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
#Return the length longest chain which can be formed.
#You do not need to use up all the given intervals. You can select pairs in any order.
# 
#Example 1:
#Input: pairs = [[1,2],[2,3],[3,4]]
#Output: 2
#Explanation: The longest chain is [1,2] -> [3,4].
#Example 2:
#Input: pairs = [[1,2],[7,8],[4,5]]
#Output: 3
#Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
# 
#Constraints:
#	n == pairs.length
#	1 <= n <= 1000
#	-1000 <= lefti < righti <= 1000
class Solution(object):
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 1
        #2. For each pair in pairs, check if it is greater than the last pair in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #pairs: [[1,2],[2,3],[3,4]]
        #ret: 2
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = 1
        for pair in pairs:
            for i in range(len(ret)):
                if pair[0] > ret[i][-1]:
                    ret.append(ret[i] + [pair])
            ret.append(pair)

        return ret