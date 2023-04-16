#https://leetcode.com/problems/count-ways-to-build-good-strings/
#Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
#Append the character '0' zero times.
#Append the character '1' one times.
#This can be performed any number of times.
#A good string is a string constructed by the above process having a length between low and high (inclusive).
#Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.


class Solution(object):
    def countGoodStrings(self, low, high, zero, one):
        """
        :type low: int
        :type high: int
        :type zero: int
        :type one: int
        :rtype: int
        """ 
        self.count=0
        self.dfs(low,high,zero,one,"")
        return self.count
        

    