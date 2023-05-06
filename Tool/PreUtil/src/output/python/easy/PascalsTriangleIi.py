#https://leetcode.com/problems/pascals-triangle-ii/
#Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
#In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        res=[]
        for i in range(rowIndex+1):
            if i==0:
                res.append(1)
            elif i==1:
                res.append(1)
            else:
                temp=[1]
                for j in range(i-1):
                    temp.append(res[j]+res[j+1])
                temp.append(1)
                res=temp
        return res

    