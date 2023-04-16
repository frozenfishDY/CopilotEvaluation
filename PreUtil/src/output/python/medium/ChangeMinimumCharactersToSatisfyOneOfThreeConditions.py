#https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
#You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.
#Your goal is to satisfy one of the following three conditions:
#Every letter in a is strictly less than every letter in b in the alphabet.
#Every letter in b is strictly less than every letter in a in the alphabet.
#Both a and b consist of only one distinct letter.
#Return the minimum number of operations needed to achieve your goal.


class Solution(object):
    def minCharacters(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """       
        # 1. Get the frequency of each character in a and b
        # 2. Get the minimum number of operations to satisfy each condition
        # 3. Return the minimum of the minimum number of operations to satisfy each condition
        a_freq = self.get_freq(a)
        b_freq = self.get_freq(b)
        return min(self.get_operations(a_freq, b_freq), self.get_operations(b_freq, a_freq), self.get_operations_same(a_freq, b_freq))

        

    