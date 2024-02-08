#https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
#Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
#Return the maximum possible product of the lengths of the two palindromic subsequences.
#A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.


class Solution(object):
    def maxProduct(self, s):
        """
        :type s: str
        :rtype: int
        """   
        # 1. Get all the palindromes
        # 2. Loop through the palindromes and get the product of the length of the two palindromes
        # 3. If the product is greater than the result, then update the result
        # 4. Return the result
        palindromes = self.get_palindromes(s)
        result = 0
        for i in range(len(palindromes)):
            for j in range(i + 1, len(palindromes)):
                result = max(result, len(palindromes[i]) * len(palindromes[j]))
        return result

        

    