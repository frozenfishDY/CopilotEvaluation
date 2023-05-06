#https://leetcode.com/problems/camelcase-matching/
#Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.
#A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.


class Solution(object):
    def camelMatch(self, queries, pattern):
        """
        :type queries: List[str]
        :type pattern: str
        :rtype: List[bool]
        """
        res = []
        for query in queries:
            i = 0
            for c in query:
                if i < len(pattern) and c == pattern[i]:
                    i += 1
                elif c.isupper():
                    i = -1
                    break
            res.append(i == len(pattern))
        return res
        

    