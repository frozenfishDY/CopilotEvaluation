#https://leetcode.com/problems/print-words-vertically/
#Given a string s. Return all the words vertically in the same order in which they appear in s.
#Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
#Each word would be put on only one column and that in one column there will be only one word.


class Solution(object):
    def printVertically(self, s):
        """
        :type s: str
        :rtype: List[str]
        """                    
        words = s.split()
        max_len = max([len(word) for word in words])
        res = []
        for i in range(max_len):
            temp = ""
            for word in words:
                if i < len(word):
                    temp += word[i]
                else:
                    temp += " "
            res.append(temp.rstrip())
        return res

        

    