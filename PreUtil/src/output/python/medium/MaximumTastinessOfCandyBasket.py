#https://leetcode.com/problems/maximum-tastiness-of-candy-basket/
#You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.
#The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute difference of the prices of any two candies in the basket.
#Return the maximum tastiness of a candy basket.


class Solution(object):
    def maximumTastiness(self, price, k):
        """
        :type price: List[int]
        :type k: int
        :rtype: int
        """
        res = 0
        for i in range(len(price)):
            for j in range(i+1,len(price)):
                if abs(price[i]-price[j]) > res:
                    res = abs(price[i]-price[j])
        return res
        

    