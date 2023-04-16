#https://leetcode.com/problems/maximum-number-of-eaten-apples/
#There is a special kind of apple tree that grows apples every day for n days. On the ith day, the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.
#You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.
#Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.


class Solution(object):
    def eatenApples(self, apples, days):
        """
        :type apples: List[int]
        :type days: List[int]
        :rtype: int
        """
        result = 0
        for i in range(len(apples)):
            if apples[i] > 0:
                for j in range(i, i+days[i]):
                    if j < len(apples) and apples[j] > 0:
                        apples[j] -= 1
                        result += 1
                        break
        return result
        

    