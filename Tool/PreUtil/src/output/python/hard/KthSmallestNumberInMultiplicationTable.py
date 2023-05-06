#https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
#Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).
#Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.


class Solution(object):
    def findKthNumber(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        if m>n:
            m,n=n,m
        left=1
        right=m*n
        while left<right:
            mid=(left+right)//2
            if self.count(mid,m,n)<k:
                left=mid+1
            else:
                right=mid
        return left
        
        
    