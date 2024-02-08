#https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
#Let's define a function countUniqueChars(s) that returns the number of unique characters on s.
#For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
#Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.
#Notice that some substrings can be repeated so in this case you have to count the repeated ones too.


class Solution(object):
    def uniqueLetterString(self, s):
        """
        :type s: str
        :rtype: int
        """       
        # 1. find the number of unique characters in each substring
        # 2. return the sum of the number of unique characters in each substring
        return self.find_unique_chars(s)

        
        
    