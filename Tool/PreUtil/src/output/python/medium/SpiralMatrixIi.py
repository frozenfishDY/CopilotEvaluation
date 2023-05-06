#https://leetcode.com/problems/spiral-matrix-ii/
#Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.


class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """ 
        res = [[0] * n for _ in range(n)]
        left, right, top, bottom = 0, n - 1, 0, n - 1
        num = 1
        while left <= right and top <= bottom:
            for i in range(left, right + 1):
                res[top][i] = num
                num += 1
            for i in range(top + 1, bottom + 1):
                res[i][right] = num
                num += 1
            if left < right and top < bottom:
                for i in range(right - 1, left, -1):
                    res[bottom][i] = num
                    num += 1
                for i in range(bottom, top, -1):
                    res[i][left] = num
                    num += 1
            left, right, top, bottom = left + 1, right - 1, top + 1, bottom - 1
        return res
        

    