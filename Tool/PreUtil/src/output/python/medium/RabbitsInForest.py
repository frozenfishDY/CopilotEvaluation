#https://leetcode.com/problems/rabbits-in-forest/
#There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
#Given the array answers, return the minimum number of rabbits that could be in the forest.


class Solution(object):
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        if not answers:
            return 0
        count = collections.Counter(answers)
        res = 0
        for key, value in count.items():
            res += (value + key) // (key + 1) * (key + 1)
        return res
        

    