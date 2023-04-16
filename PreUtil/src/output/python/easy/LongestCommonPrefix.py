#https://leetcode.com/problems/longest-common-prefix/
#Write a function to find the longest common prefix string amongst an array of strings.
#If there is no common prefix, return an empty string "".


class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)==0:
            return ""
        elif len(strs)==1:
            return strs[0]
        else:
            res=""
            for i in range(0,len(strs[0])):
                for j in range(1,len(strs)):
                    if i>=len(strs[j]) or strs[0][i]!=strs[j][i]:
                        return res
                res=res+strs[0][i]
            return res

    