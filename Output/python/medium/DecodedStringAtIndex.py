#https://leetcode.com/problems/decoded-string-at-index/
#You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:
#If the character read is a letter, that letter is written onto the tape.
#If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
#Given an integer k, return the kth letter (1-indexed) in the decoded string.


class Solution(object):
    def decodeAtIndex(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        stack = []
        for c in s:
            if c.isdigit():
                stack.append(int(c) * stack.pop())
            else:
                stack.append(c)
        while stack:
            temp = stack.pop()
            if isinstance(temp, int):
                k = k % temp
                if k == 0:
                    k = temp
            else:
                if k == 1:
                    return temp
                k -= 1
        return ""
        

    