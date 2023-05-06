#https://leetcode.com/problems/palindrome-pairs/
#You are given a 0-indexed array of unique strings words.
#A palindrome pair is a pair of integers (i, j) such that:
#0 <= i, j < words.length,
#i != j, and
#words[i] + words[j] (the concatenation of the two strings) is a palindrome.
#Return an array of all the palindrome pairs of words.


class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """       
        if not words:
            return []
        result = []
        for i in range(len(words)):
            for j in range(len(words)):
                if i != j and self.isPalindrome(words[i]+words[j]):
                    result.append([i,j])
        return result
            
          
        
    