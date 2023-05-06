#https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/
#You are given a 0-indexed integer array forts of length n representing the positions of several forts. forts[i] can be -1, 0, or 1 where:
#-1 represents there is no fort at the ith position.
#0 indicates there is an enemy fort at the ith position.
#1 indicates the fort at the ith the position is under your command.
#Now you have decided to move your army from one of your forts at position i to an empty position j such that:
#0 <= i, j <= n - 1
#The army travels over enemy forts only. Formally, for all k where min(i,j) < k < max(i,j), forts[k] == 0.
#While moving the army, all the enemy forts that come in the way are captured.
#Return the maximum number of enemy forts that can be captured. In case it is impossible to move your army, or you do not have any fort under your command, return 0.


class Solution(object):
    def captureForts(self, forts):
        """
        :type forts: List[int]
        :rtype: int
        """     
        n=len(forts)
        result=0
        for i in range(n):
            if forts[i]==1:
                j=i+1
                count=0
                while j<n:
                    if forts[j]==0:
                        count+=1
                    elif forts[j]==1:
                        break
                    j+=1
                j=i-1
                while j>=0:
                    if forts[j]==0:
                        count+=1
                    elif forts[j]==1:
                        break
                    j-=1
                result=max(result,count)
        return result
        

    