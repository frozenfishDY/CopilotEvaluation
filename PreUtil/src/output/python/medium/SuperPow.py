#https://leetcode.com/problems/super-pow/
#Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.


class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        res = 1
        for i in b:
            res = pow(res,10,1337)*pow(a,i,1337)%1337
        return res
        

    