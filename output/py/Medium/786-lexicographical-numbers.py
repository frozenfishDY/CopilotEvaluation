#https://leetcode.com/problems/lexicographical-numbers/
#Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
#You must write an algorithm that runs in O(n) time and uses O(1) extra space. 


class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """       
        return sorted([i for i in range(1,n+1)],key=lambda x:str(x))

        

    