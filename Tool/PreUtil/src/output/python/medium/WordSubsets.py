#https://leetcode.com/problems/word-subsets/
#You are given two string arrays words1 and words2.
#A string b is a subset of string a if every letter in b occurs in a including multiplicity.
#For example, "wrr" is a subset of "warrior" but is not a subset of "world".
#A string a from words1 is universal if for every string b in words2, b is a subset of a.
#Return an array of all the universal strings in words1. You may return the answer in any order.


class Solution(object):
    def wordSubsets(self, words1, words2):
        """
        :type words1: List[str]
        :type words2: List[str]
        :rtype: List[str]
        """
        res = []
        for i in range(len(words1)):
            for j in range(len(words2)):
                if words1[i] in words2[j]:
                    res.append(words1[i])
        return res
        

    