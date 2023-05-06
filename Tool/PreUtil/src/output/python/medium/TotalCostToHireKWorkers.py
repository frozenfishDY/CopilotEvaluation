#https://leetcode.com/problems/total-cost-to-hire-k-workers/
#You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.
#You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:
#You will run k sessions and hire exactly one worker in each session.
#In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
#For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
#In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
#If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
#A worker can only be chosen once.
#Return the total cost to hire exactly k workers.


class Solution(object):
    def totalCost(self, costs, k, candidates):
        """
        :type costs: List[int]
        :type k: int
        :type candidates: int
        :rtype: int
        """                                                                                               
        # 1. Sort the costs
        # 2. Get the first k costs
        # 3. Get the last k costs
        # 4. Loop through the costs from the beginning and the end
        # 5. If the number of costs from the beginning is less than k, then subtract the cost from the beginning from the total sum and add the cost from the end to the total sum
        # 6. If the number of costs from the end is less than k, then subtract the cost from the end from the total sum and add the cost from the beginning to the total sum
        # 7. Return the minimum sum
        costs.sort()
        sum_from_beginning = sum(costs[:k])
        sum_from_end = sum(costs[-k:])
        for i in range(k):
            if i < k:
                sum_from_beginning -= costs[i]
                sum_from_beginning += costs[-(i + 1)]
            if i < k:
                sum_from_end -= costs[-(i + 1)]
                sum_from_end += costs[i]
        return min(sum_from_beginning, sum_from_end)

        

    