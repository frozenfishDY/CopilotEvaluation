#https://leetcode.com/problems/interval-list-intersections/
#You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
#Return the intersection of these two interval lists.
#A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
#The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].


class Solution(object):
    def intervalIntersection(self, firstList, secondList):
        """
        :type firstList: List[List[int]]
        :type secondList: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        i = 0
        j = 0
        while i < len(firstList) and j < len(secondList):
            if firstList[i][0] <= secondList[j][1] and secondList[j][0] <= firstList[i][1]:
                res.append([max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])])
            if firstList[i][1] < secondList[j][1]:
                i += 1
            else:
                j += 1
        return res
        

    