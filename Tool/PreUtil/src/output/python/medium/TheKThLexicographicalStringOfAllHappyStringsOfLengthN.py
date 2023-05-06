#https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
#A happy string is a string that:
#consists only of letters of the set ['a', 'b', 'c'].
#s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
#For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
#Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
#Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


class Solution(object):
    def getHappyString(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """     
        # 1. Create a list of all happy strings of length n
        # 2. Sort the list
        # 3. Return the kth element
        happy_list = []
        self.get_happy_strings(n, "", happy_list)
        happy_list.sort()
        if k > len(happy_list):
            return ""
        return happy_list[k-1]

        

    