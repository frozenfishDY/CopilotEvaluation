#https://leetcode.com/problems/find-all-anagrams-in-a-string/
#Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
#An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        p_counter = collections.Counter(p)
        s_counter = collections.Counter(s[:len(p)-1])
        for i in range(len(p)-1,len(s)):
            s_counter[s[i]] += 1
        

    