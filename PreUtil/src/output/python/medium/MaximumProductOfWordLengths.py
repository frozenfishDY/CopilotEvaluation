#https://leetcode.com/problems/maximum-product-of-word-lengths/
#Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.


class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        res = 0
        words = sorted(words,key=len)
        for i in range(len(words)):
            for j in range(i+1,len(words)):
                if not set(words[i]) & set(words[j]):
                    res = max(res,len(words[i])*len(words[j]))
        return res
        

    