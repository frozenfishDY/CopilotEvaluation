#https://leetcode.com/problems/count-binary-substrings/
#Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
#Substrings that occur multiple times are counted the number of times they occur.


class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """       
        if len(s)==1:
            return 0
        if len(s)==2:
            return 1
        count=0
        for i in range(len(s)-1):
            if s[i]!=s[i+1]:
                count+=1
                left=i
                right=i+1
                while left>=0 and right<len(s) and s[left]==s[i] and s[right]==s[i+1]:
                    count+=1
                    left-=1
                    right+=1
        return count

        

    