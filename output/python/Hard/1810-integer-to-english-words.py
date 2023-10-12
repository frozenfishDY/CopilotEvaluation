#https://leetcode.com/problems/integer-to-english-words/
#Convert a non-negative integer num to its English words representation.
# 
#Example 1:
#Input: num = 123
#Output: "One Hundred Twenty Three"
#Example 2:
#Input: num = 12345
#Output: "Twelve Thousand Three Hundred Forty Five"
#Example 3:
#Input: num = 1234567
#Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
# 
#Constraints:
#	0 <= num <= 231 - 1
class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        #https://leetcode.com/problems/integer-to-english-words/discuss/70625/My-clean-Java-solution-very-easy-to-understand
        if num == 0:
            return 'Zero'
        result = ''
        for unit in ['Thousand', 'Million', 'Billion']:
            if num % 1000 != 0:
                result = self.helper(num % 1000) + ' ' + unit + ' ' + result
            num /= 1000
        return result.strip()