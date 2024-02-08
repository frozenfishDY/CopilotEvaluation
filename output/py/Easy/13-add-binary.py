#https://leetcode.com/problems/add-binary/
#Given two binary strings a and b, return their sum as a binary string.


class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        res=""
        carry=0
        i=len(a)-1
        j=len(b)-1
        while i>=0 or j>=0:
            if i>=0 and j>=0:
                res=str((int(a[i])+int(b[j])+carry)%2)+res
                carry=(int(a[i])+int(b[j])+carry)/2
            elif i>=0:
                res=str((int(a[i])+carry)%2)+res
                carry=(int(a[i])+carry)/2
            else:
                res=str((int(b[j])+carry)%2)+res
                carry=(int(b[j])+carry)/2
            i=i-1
            j=j-1
        if carry==1:
            res="1"+res
        return res

    