#https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
#You are given an array of n strings strs, all of the same length.
#We may choose any deletion indices, and we delete all the characters in those indices for each string.
#For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
#Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.


class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        if not strs:
            return 0
        if len(strs)==1:
            return 0
        if len(strs[0])==1:
            return 0
        result = 0
        for i in range(len(strs[0])):
            for j in range(len(strs)-1):
                if strs[j][i]>strs[j+1][i]:
                    result+=1
                    break
        return result
        
        
    