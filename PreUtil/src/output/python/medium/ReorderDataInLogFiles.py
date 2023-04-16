#https://leetcode.com/problems/reorder-data-in-log-files/
#You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.
#There are two types of logs:
#Letter-logs: All words (except the identifier) consist of lowercase English letters.
#Digit-logs: All words (except the identifier) consist of digits.
#Reorder these logs so that:
#The letter-logs come before all digit-logs.
#The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
#The digit-logs maintain their relative ordering.
#Return the final order of the logs.


class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        def f(log):
            id_, rest = log.split(" ", 1)
            return (0, rest, id_) if rest[0].isalpha() else (1,)
        return sorted(logs, key=f)
        

    