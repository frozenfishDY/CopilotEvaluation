#https://leetcode.com/problems/groups-of-special-equivalent-strings/
#You are given an array of strings of the same length words.
#In one move, you can swap any two even indexed characters or any two odd indexed characters of a string words[i].
#Two strings words[i] and words[j] are special-equivalent if after any number of moves, words[i] == words[j].
#For example, words[i] = "zzxy" and words[j] = "xyzz" are special-equivalent because we may make the moves "zzxy" -> "xzzy" -> "xyzz".
#A group of special-equivalent strings from words is a non-empty subset of words such that:
#Every pair of strings in the group are special equivalent, and
#The group is the largest size possible (i.e., there is not a string words[i] not in the group such that words[i] is special-equivalent to every string in the group).
#Return the number of groups of special-equivalent strings from words.


class Solution(object):
    def numSpecialEquivGroups(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        res = set()
        for word in words:
            res.add(self.getSpecialEquivalent(word))
        return len(res)
        

    