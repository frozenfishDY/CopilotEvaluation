#https://leetcode.com/problems/super-egg-drop/
#You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
#You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
#Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
#Return the minimum number of moves that you need to determine with certainty what the value of f is.


class Solution(object):
    def superEggDrop(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: int
        """
        if k==1:
            return n
        if n==1:
            return 1
        result=0
        for i in range(n):
            result=max(result,self.superEggDropHelper(k,n,i))
        return result
        
        
    