#https://leetcode.com/problems/number-of-segments-in-a-string/
#Given a string s, return the number of segments in the string.
#A segment is defined to be a contiguous sequence of non-space characters.


class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """ 
        if len(s)==0:
            return 0
        if len(s)==1:
            if s[0]==" ":
                return 0
            else:
                return 1
        count=0
        for i in range(0,len(s)-1):
            if s[i]==" " and s[i+1]!=" ":
                count+=1
        if s[len(s)-1]!=" ":
            count+=1
        return count

    