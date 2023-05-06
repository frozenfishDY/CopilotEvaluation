#https://leetcode.com/problems/shifting-letters/
#You are given a string s of lowercase English letters and an integer array shifts of the same length.
#Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
#For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
#Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
#Return the final string after all such shifts to s are applied.


class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[int]
        :rtype: str
        """
        res = ""
        for i in range(len(shifts) - 2, -1, -1):
            shifts[i] += shifts[i + 1]
        for i in range(len(s)):
            res += chr((ord(s[i]) - ord('a') + shifts[i]) % 26 + ord('a'))
        return res
        

    