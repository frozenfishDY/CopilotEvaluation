#https://leetcode.com/problems/profitable-schemes/
#There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.
#Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.
#Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 10^9 + 7.


class Solution(object):
    def profitableSchemes(self, n, minProfit, group, profit):
        """
        :type n: int
        :type minProfit: int
        :type group: List[int]
        :type profit: List[int]
        :rtype: int
        """
        if len(group)==1:
            if group[0]<=n and profit[0]>=minProfit:
                return 1
            else:
                return 0
        result=0
        for i in range(len(group)):
            result+=self.profitableSchemesHelper(n,minProfit,group,profit,i)
        return result
        
        
    