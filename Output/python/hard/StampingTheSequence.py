#https://leetcode.com/problems/stamping-the-sequence/
#You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.
#In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.
#For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
#place stamp at index 0 of s to obtain "abc??",
#place stamp at index 1 of s to obtain "?abc?", or
#place stamp at index 2 of s to obtain "??abc".
#Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
#We want to convert s to target using at most 10 * target.length turns.
#Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.


class Solution(object):
    def movesToStamp(self, stamp, target):
        """
        :type stamp: str
        :type target: str
        :rtype: List[int]
        """
        if not stamp:
            return []
        if not target:
            return []
        if len(stamp)>len(target):
            return []
        if len(stamp)==len(target):
            if stamp==target:
                return [0]
            else:
                return []
        result = []
        for i in range(len(target)-len(stamp)+1):
            if target[i:i+len(stamp)]==stamp:
                result.append(i)
        return result
        
        
    