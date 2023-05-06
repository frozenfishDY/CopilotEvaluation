#https://leetcode.com/problems/string-without-aaa-or-bbb/
#Given two integers a and b, return any string s such that:
#s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
#The substring 'aaa' does not occur in s, and
#The substring 'bbb' does not occur in s.


class Solution(object):
    def strWithout3a3b(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: str
        """
        res = ""
        while a > 0 or b > 0:
            if a > b:
                if a > 1:
                    res += "aa"
                    a -= 2
                else:
                    res += "a"
                    a -= 1
                if b > 0:
                    res += "b"
                    b -= 1
            else:
                if b > 1:
                    res += "bb"
                    b -= 2
                else:
                    res += "b"
                    b -= 1
                if a > 0:
                    res += "a"
                    a -= 1
        return res
        

    