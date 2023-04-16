#https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
#You are given a 0-indexed string text and another 0-indexed string pattern of length 2, both of which consist of only lowercase English letters.
#You can add either pattern[0] or pattern[1] anywhere in text exactly once. Note that the character can be added even at the beginning or at the end of text.
#Return the maximum number of times pattern can occur as a subsequence of the modified text.
#A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.


class Solution(object):
    def maximumSubsequenceCount(self, text, pattern):
        """
        :type text: str
        :type pattern: str
        :rtype: int
        """                
        if len(text)==0:
            return 0
        if len(text)==1:
            if text[0]==pattern[0] or text[0]==pattern[1]:
                return 1
            else:
                return 0
        if len(text)==2:
            if text[0]==pattern[0] and text[1]==pattern[1]:
                return 1
            if text[0]==pattern[1] and text[1]==pattern[0]:
                return 1
            if text[0]==pattern[0] or text[0]==pattern[1]:
                return 1
            if text[1]==pattern[0] or text[1]==pattern[1]:
                return 1
            return 0
        if len(text)==3:
            if text[0]==pattern[0] and text[1]==pattern[1]:
                return 1
            if text[0]==pattern[1] and text[1]==pattern[0]:
                return 1
            if text[0]==pattern[0] or text[0]==pattern[1]:
                return 1
            if text[1]==pattern[0] or text[1]==pattern[1]:
                return 1
            if text[2]==pattern[0] or text[2]==pattern[1]:
                return 1
            return 0
        if len(text)==4:
            if text[0]==pattern[0] and text[1]==pattern[1]:
                return 1
            if text[0]==pattern[1] and text[1]==pattern[0]:
                return 1
            if text[0]==pattern[0] or text[0]==pattern[1]:
                return 1
            if text[1]==pattern[0] or text[1]==pattern[1]:
                return 1
            if text[2]==pattern[0] or text[2]==pattern[1]:
                return 1
            if text[3]==pattern[0] or text[3]==pattern[1]:
                return 1
            return 0
        if len(text)==5:
            if text[0]==pattern[0] and text[1]==pattern[1]:
                return 1
            if text[0]==pattern[1] and text[1]==pattern[0]:
                return 1

        

    