#https://leetcode.com/problems/pascals-triangle/
#Given an integer numRows, return the first numRows of Pascal's triangle.
#In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res=[]
        for i in range(numRows):
            if i==0:
                res.append([1])
            elif i==1:
                res.append([1,1])
            else:
                temp=[1]
                for j in range(i-1):
                    temp.append(res[i-1][j]+res[i-1][j+1])
                temp.append(1)
                res.append(temp)
        return res
        
    