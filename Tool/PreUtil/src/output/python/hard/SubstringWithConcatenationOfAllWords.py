#https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#You are given a string s and an array of strings words. All the strings of words are of the same length.
#A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
#For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
#Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.


class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """      
        if not words:
            return []
        if not s:
            return []
        word_len=len(words[0])
        word_num=len(words)
        s_len=len(s)
        if s_len<word_len*word_num:
            return []
        res=[]
        for i in range(s_len-word_len*word_num+1):
            if self.isMatch(s[i:i+word_len*word_num],words):
                res.append(i)
        return res
        
    