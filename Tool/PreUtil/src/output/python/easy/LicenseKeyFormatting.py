#https://leetcode.com/problems/license-key-formatting/
#You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
#We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
#Return the reformatted license key.


class Solution(object):
    def licenseKeyFormatting(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        s=s.replace("-","")
        s=s.upper()
        if len(s)<=k:
            return s
        else:
            s=s[::-1]
            s=s[0:k]+"-"+s[k:]
            s=s[::-1]
            for i in range(k+1,len(s)):
                if s[i]=="-":
                    s=s[0:i+1]+s[i+1].upper()+s[i+2:]
            return s

    