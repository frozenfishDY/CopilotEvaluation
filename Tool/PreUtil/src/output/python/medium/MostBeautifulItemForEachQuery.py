#https://leetcode.com/problems/most-beautiful-item-for-each-query/
#You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.
#You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.
#Return an array answer of the same length as queries where answer[j] is the answer to the jth query.


class Solution(object):
    def maximumBeauty(self, items, queries):
        """
        :type items: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        result=[]
        for i in range(len(queries)):
            result.append(max([items[j][1] for j in range(len(items)) if items[j][0]<=queries[i]]+[0]))
        return result
        

    