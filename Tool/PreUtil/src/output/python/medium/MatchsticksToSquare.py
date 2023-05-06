#https://leetcode.com/problems/matchsticks-to-square/
#You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
#Return true if you can make this square and false otherwise.


class Solution(object):
    def makesquare(self, matchsticks):
        """
        :type matchsticks: List[int]
        :rtype: bool
        """
        res = 0
        for i in range(len(matchsticks)):
            for j in range(i+1,len(matchsticks)):
                for k in range(j+1,len(matchsticks)):
                    for l in range(k+1,len(matchsticks)):
                        if matchsticks[i]+matchsticks[j]+matchsticks[k]+matchsticks[l] == 0:
                            return True
        return False
        

    