#https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
#There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
#We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
#Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
#Every worker in the paid group must be paid at least their minimum wage expectation.
#Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.


class Solution(object):
    def mincostToHireWorkers(self, quality, wage, k):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type k: int
        :rtype: float
        """                                                           
        if k==1:
            return min(wage)
        if k==len(quality):
            return sum(wage)/len(quality)
        result=[]
        for i in range(len(quality)):
            result.append(self.mincostToHireWorkersHelper(quality,wage,k,i))
        return min(result) 










        
        
    