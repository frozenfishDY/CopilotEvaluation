#https://leetcode.com/problems/repeated-dna-sequences/
#The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
#For example, "ACGAATTCCG" is a DNA sequence.
#When studying DNA, it is useful to identify repeated sequences within the DNA.
#Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.


class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        for i in range(len(s)-9):
            if s[i:i+10] in s[i+1:]:
                res.append(s[i:i+10])
        return list(set(res))
        

    