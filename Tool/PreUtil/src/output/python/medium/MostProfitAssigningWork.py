#https://leetcode.com/problems/most-profit-assigning-work/
#You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
#difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
#worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
#Every worker can be assigned at most one job, but one job can be completed multiple times.
#For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
#Return the maximum profit we can achieve after assigning the workers to the jobs.


class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """       
        jobs = sorted(zip(difficulty, profit))
        jobs.append((float('inf'), 0))
        res = i = best = 0
        for ability in sorted(worker):
            while ability >= jobs[i][0]:
                best = max(best, jobs[i][1])
                i += 1
            res += best
        return res
            
         
        

    