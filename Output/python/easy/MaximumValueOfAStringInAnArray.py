#https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/
#The value of an alphanumeric string can be defined as:
#The numeric representation of the string in base 10, if it comprises of digits only.
#The length of the string, otherwise.
#Given an array strs of alphanumeric strings, return the maximum value of any string in strs.


class Solution(object):
    def maximumValue(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """       
        max_value=0
        for i in range(len(strs)):
            if strs[i].isdigit():
                max_value=max(max_value,int(strs[i]))
            else:
                max_value=max(max_value,len(strs[i]))
        return max_value
        

    