#https://leetcode.com/problems/last-stone-weight-ii/
#You are given an array of integers stones where stones[i] is the weight of the ith stone.
#We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:
#	If x == y, both stones are destroyed, and
#	If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
#At the end of the game, there is at most one stone left.
#Return the smallest possible weight of the left stone. If there are no stones left, return 0.
# 
#Example 1:
#Input: stones = [2,7,4,1,8,1]
#Output: 1
#Explanation:
#We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
#we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
#we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
#we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
#Example 2:
#Input: stones = [31,26,33,21,40]
#Output: 5
# 
#Constraints:
#	1 <= stones.length <= 30
#	1 <= stones[i] <= 100
class Solution(object):
    def lastStoneWeightII(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in stones, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #stones: [2,7,4,1,8,1]
        #ret: 1
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = 0
        for num in stones:
            for i in range(len(ret)):
                if num > ret[i]:
                    ret[i] = num

        return ret