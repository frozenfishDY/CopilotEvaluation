#https://leetcode.com/problems/bag-of-tokens/
#You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).
#Your goal is to maximize your total score by potentially playing each token in one of two ways:
#If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
#If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
#Each token may be played at most once and in any order. You do not have to play all the tokens.
#Return the largest possible score you can achieve after playing any number of tokens.


class Solution(object):
    def bagOfTokensScore(self, tokens, power):
        """
        :type tokens: List[int]
        :type power: int
        :rtype: int
        """
        tokens.sort()
        res = 0
        score = 0
        i = 0
        j = len(tokens) - 1
        while i <= j:
            if power >= tokens[i]:
                power -= tokens[i]
                score += 1
                i += 1
                res = max(res, score)
            elif score > 0:
                power += tokens[j]
                score -= 1
                j -= 1
            else:
                break
        return res
        

    