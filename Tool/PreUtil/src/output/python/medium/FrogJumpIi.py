#https://leetcode.com/problems/frog-jump-ii/
#You are given a 0-indexed integer array stones sorted in strictly increasing order representing the positions of stones in a river.
#A frog, initially on the first stone, wants to travel to the last stone and then return to the first stone. However, it can jump to any stone at most once.
#The length of a jump is the absolute difference between the position of the stone the frog is currently on and the position of the stone to which the frog jumps.
#More formally, if the frog is at stones[i] and is jumping to stones[j], the length of the jump is |stones[i] - stones[j]|.
#The cost of a path is the maximum length of a jump among all jumps in the path.
#Return the minimum cost of a path for the frog.


class Solution(object):
    def maxJump(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """                   
        res = 0
        for i in range(len(stones)):
            for j in range(i+1,len(stones)):
                if stones[j] == stones[i]*stones[i]:
                    res = max(res,j-i+1)
                elif stones[j] > stones[i]*stones[i]:
                    break
        return res if res > 1 else -1

        

    