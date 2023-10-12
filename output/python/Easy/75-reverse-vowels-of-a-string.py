#https://leetcode.com/problems/reverse-vowels-of-a-string/
#Given a string s, reverse only all the vowels in the string and return it.
#The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
# 
#Example 1:
#Input: s = "hello"
#Output: "holle"
#Example 2:
#Input: s = "leetcode"
#Output: "leotcede"
# 
#Constraints:
#	1 <= s.length <= 3 * 105
#	s consist of printable ASCII characters.
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ['a', 'e', 'i', 'o', 'u']
        s = list(s)
        l = 0
        r = len(s)-1
        while l < r:
            if s[l].lower() not in vowels:
                l += 1
            elif s[r].lower() not in vowels:
                r -= 1
            else:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1
        return ''.join(s)