#https://leetcode.com/problems/fair-distribution-of-cookies/
#You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.
#The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
#Return the minimum unfairness of all distributions.


class Solution(object):
    def distributeCookies(self, cookies, k):
        """
        :type cookies: List[int]
        :type k: int
        :rtype: int
        """
        cookies.sort()
        result=0
        for i in range(k):
            result+=cookies[-1-i]
        return result
        
    