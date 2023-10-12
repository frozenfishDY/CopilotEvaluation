#https://leetcode.com/problems/maximum-number-of-balloons/
#Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
#You can use each character in text at most once. Return the maximum number of instances that can be formed.
# 
#Example 1:
#Input: text = "nlaebolko"
#Output: 1
#Example 2:
#Input: text = "loonbalxballpoon"
#Output: 2
#Example 3:
#Input: text = "leetcode"
#Output: 0
# 
#Constraints:
#	1 <= text.length <= 104
#	text consists of lower case English letters only.
class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        return min(text.count('b'),text.count('a'),text.count('l')/2,text.count('o')/2,text.count('n'))
